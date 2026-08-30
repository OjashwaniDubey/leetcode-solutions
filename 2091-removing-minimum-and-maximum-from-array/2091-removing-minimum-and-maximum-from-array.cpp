class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int minIdx = -1;
        int maxIdx = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == mx) maxIdx = i;
            if(nums[i] == mn) minIdx = i;  
        }
        int l = min(maxIdx, minIdx);
        int r = max(minIdx, maxIdx);
        int ans = min(r+1, min(n-l, l + 1 + n - r));
        return ans;
    }
};