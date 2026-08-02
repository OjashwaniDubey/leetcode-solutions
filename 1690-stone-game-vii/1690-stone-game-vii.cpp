class Solution {
public:
    int sumLeft(int i, int j, vector<int>& prefix){
        if(i > j) return 0;
        return prefix[j+1] - prefix[i];
    }
    int f(int i, int j, vector<int>& stones, vector<int>& prefix, vector<vector<int>>& dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int takeLeft = sumLeft(i+1, j, prefix) - f(i+1, j, stones, prefix, dp);
        int takeRight = sumLeft(i, j-1, prefix) - f(i, j-1, stones, prefix, dp);
        return dp[i][j] = max(takeLeft, takeRight);
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + stones[i];
        }
        for(int i = 0; i < n; i++){
            dp[i][i] = 0;
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                int takeLeft = prefix[j+1] - prefix[i+1] - dp[i+1][j];
                int takeRight = prefix[j] - prefix[i] - dp[i][j-1];
                dp[i][j] = max(takeLeft, takeRight);
            }
        }
        return dp[0][n-1];
    }
};