class Solution {
public:
    long long f(int idx, vector<vector<int>>& q, vector<long long>& dp){
        if(idx >= q.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long take = q[idx][0] + f(idx+q[idx][1]+1, q, dp);
        long long notTake = f(idx+1, q, dp);
        return dp[idx] = max(take, notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        int m = questions[0].size();
        vector<long long>dp(n+1, 0);
        for(int i = n-1; i >= 0; i--){
            long long next = i + questions[i][1] + 1;
            long long take = questions[i][0];
            if(next < n) take += dp[next];
            dp[i] = max(take, dp[i+1]);
        }
        return dp[0];
    }
};