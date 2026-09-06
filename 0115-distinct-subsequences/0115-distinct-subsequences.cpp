class Solution {
public:
    int solve(int idx1, int idx2, string& s, string& t, vector<vector<int>>& dp){
        if(idx2 == t.size()) return 1;
        if(idx1 == s.size()) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s[idx1] == t[idx2]) return dp[idx1][idx2] = solve(idx1+1, idx2+1, s, t, dp) + solve(idx1+1, idx2, s, t, dp);
        return dp[idx1][idx2] = solve(idx1+1, idx2, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s, t, dp);
    }
};