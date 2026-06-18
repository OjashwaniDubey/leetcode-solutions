class Solution {
public:
    int f(int idx1, int idx2, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(idx1 > idx2) return 0;
        int maxi = 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        for(int k = idx1; k <= idx2; k++){
            int steps = nums[idx1-1] * nums[k] * nums[idx2+1] + f(idx1, k-1, nums, dp) + f(k+1, idx2, nums, dp);
            maxi = max(maxi, steps);
        }
        return dp[idx1][idx2] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, n, nums, dp);
    }
};