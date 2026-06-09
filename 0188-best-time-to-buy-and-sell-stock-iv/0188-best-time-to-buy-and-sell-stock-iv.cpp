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
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 1, k, prices, dp);
    }
};