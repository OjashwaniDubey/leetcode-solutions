class Solution {
public:
    int f(int idx, int prev_idx, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(idx == n) return 0;
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];
        int length = 0 + f(idx+1, prev_idx, nums, dp);
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
            length = max(length, 1 + f(idx+1, idx, nums, dp));
        }
        return dp[idx][prev_idx+1] = length;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, dp);
    }
};