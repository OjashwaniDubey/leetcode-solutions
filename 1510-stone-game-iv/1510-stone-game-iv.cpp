class Solution {
public:
    bool f(int n, vector<int>& dp){
        if(n == 0) return false;
        if(dp[n] != -1) return dp[n];
        for(int j = 1; j * j <= n; j++){
            if(!f(n - j*j, dp)) return dp[n] = true;
        }
        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        dp[0] = false;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j*j <= i; j++){
                if(!dp[i - j*j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};