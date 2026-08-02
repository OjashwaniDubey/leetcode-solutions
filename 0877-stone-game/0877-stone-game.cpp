class Solution {
public:
    int f(int i, int j, vector<int>& piles, vector<vector<int>>& dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int takeLeft = piles[i] - f(i+1, j, piles, dp);
        int takeRight = piles[j] - f(i, j-1, piles, dp);
        return dp[i][j] = max(takeLeft, takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 0;
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                int takeLeft = piles[i] - dp[i+1][j];
                int takeRight = piles[j] - dp[i][j-1];
                dp[i][j] = max(takeLeft, takeRight);
            }
        }
        return dp[0][n-1] >= 0;
    }
};