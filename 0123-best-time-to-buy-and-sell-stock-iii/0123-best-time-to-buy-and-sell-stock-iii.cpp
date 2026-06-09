class Solution {
public:
    int f(int idx, int buy, int limit, vector<int>& prices, vector<vector<vector<int>>>& dp){
        int n = prices.size();
        if(idx == n) return 0;
        if(limit == 0) return 0;
        if(dp[idx][buy][limit] != -1) return dp[idx][buy][limit];
        if(buy){
            return dp[idx][buy][limit] = max(-prices[idx] + f(idx+1, 0, limit, prices, dp), f(idx+1, 1, limit, prices, dp));
        }
        else{
            return dp[idx][buy][limit] = max(prices[idx] + f(idx+1, 1, limit-1, prices, dp), f(idx+1, 0, limit, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                for(int k = 1; k < 3; k++){
                    if(j == 1) dp[i][j][k] = max(-prices[i]+dp[i+1][0][k], dp[i+1][1][k]);
                    else dp[i][j][k] = max(prices[i]+dp[i+1][1][k-1], dp[i+1][0][k]);
                }
            }
        }
        return dp[0][1][2];
    }
};