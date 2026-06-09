class Solution {
public:
    int f(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();
        if(idx == n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy){
            return dp[idx][buy] = max(-prices[idx] + f(idx+1, 0, prices, dp), 0 + f(idx+1, 1, prices, dp));
        }
        else{
            return dp[idx][buy] = max(prices[idx] + f(idx+1, 1, prices, dp), 0 + f(idx+1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                if(j == 1){
                    dp[i][j] = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][j]);
                }
                else{
                    dp[i][j] = max(prices[i] + dp[i+1][1], 0 + dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};