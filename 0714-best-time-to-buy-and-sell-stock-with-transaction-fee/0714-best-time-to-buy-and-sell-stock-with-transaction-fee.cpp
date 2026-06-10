class Solution {
public:
    int f(int idx, int buy, vector<int>& p, int fee, vector<vector<int>>& dp){
        int n = p.size();
        if(idx == n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy){
            return dp[idx][buy] = max(-p[idx]+f(idx+1, 0, p, fee, dp), f(idx+1, 1, p, fee, dp));
        }
        else{
            return dp[idx][buy] = max(p[idx]+f(idx+1, 1, p, fee, dp)-fee, f(idx+1, 0, p, fee, dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        for(int i = n-1; i >= 0; i--){
            dp[i][1] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
            dp[i][0] = max(prices[i]+dp[i+1][1]-fee, dp[i+1][0]);
        }
        return dp[0][1];
    }
};