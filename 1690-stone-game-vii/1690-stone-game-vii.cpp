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
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + stones[i];
        }
        return f(0, n-1, stones, prefix, dp);
    }
};