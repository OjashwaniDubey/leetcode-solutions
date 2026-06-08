class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> less;
        vector<int> equal;
        vector<int> more;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) less.push_back(nums[i]);
            else if(nums[i] == pivot) equal.push_back(nums[i]);
            else more.push_back(nums[i]);
        }
        vector<int> ans = less;
        ans.insert(ans.end(), equal.begin(), equal.end());
        ans.insert(ans.end(), more.begin(), more.end());
        return ans;
    }
};