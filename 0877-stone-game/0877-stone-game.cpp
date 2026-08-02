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
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, piles, dp) >= 0;
    }
};