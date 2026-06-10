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
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return f(0, 1, prices, fee, dp);
    }
};