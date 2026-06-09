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
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};