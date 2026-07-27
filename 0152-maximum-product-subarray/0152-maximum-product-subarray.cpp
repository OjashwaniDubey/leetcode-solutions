class Solution {
public:
    vector<int> dpmax, dpmin;
    vector<bool> vis;
    pair<int, int> f(int index, vector<int>& nums){
        int n = nums.size();
        if(vis[index]){
            return {dpmax[index], dpmin[index]};
        }
        vis[index] = true;
        if(index == n - 1){
            dpmax[index] = nums[index];
            dpmin[index] = nums[index];
            return {dpmax[index], dpmin[index]};
        }
        auto next = f(index+1, nums);
        dpmax[index] = max({nums[index], nums[index]*next.first, nums[index]*next.second});
        dpmin[index] = min({nums[index], nums[index]*next.first, nums[index]*next.second});
        return {dpmax[index], dpmin[index]};
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        dpmax.assign(n, 0);
        dpmin.assign(n, 0);
        vis.assign(n, false);
        f(0, nums);
        int ans = INT_MIN;
        for(int d : dpmax){
            ans = max(ans, d);
        }
        return ans;
    }
};