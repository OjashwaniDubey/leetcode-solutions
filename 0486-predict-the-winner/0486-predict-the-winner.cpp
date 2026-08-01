class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int takeLeft = nums[i] - f(i+1, j, nums, dp);
        int takeRight = nums[j] - f(i, j-1, nums, dp);
        return dp[i][j] = max(takeLeft, takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = nums[i];
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                int takeLeft = nums[i] - dp[i+1][j];
                int takeRight = nums[j] - dp[i][j-1];
                dp[i][j] = max(takeLeft, takeRight);
            }
        }
        return dp[0][n-1] >= 0;
    }
};