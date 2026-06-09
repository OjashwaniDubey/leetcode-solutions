class Solution {
public:
    int f(int idx, int buy, int k, vector<int>& p, vector<vector<vector<int>>>& dp){
        int n = p.size();
        if(k == 0) return 0;
        if(idx == n) return 0;
        if(dp[idx][buy][k] != -1) return dp[idx][buy][k];
        if(buy) return dp[idx][buy][k] = max(-p[idx]+f(idx+1, 0, k, p, dp), f(idx+1, 1, k, p, dp));
        else return dp[idx][buy][k] = max(p[idx]+f(idx+1, 1, k-1, p, dp), f(idx+1, 0, k, p, dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                for(int cap = 1; cap <= k; cap++){
                    if(j == 1) dp[i][j][cap] = max(-prices[i]+dp[i+1][0][cap], dp[i+1][1][cap]);
                    else dp[i][j][cap] = max(prices[i]+dp[i+1][1][cap-1], dp[i+1][0][cap]);
                }
            }
        }
        return dp[0][1][k];
    }
};