class Solution {
public:
    bool f(int idx1, int idx2, string& s, string& p, vector<vector<int>>& dp){
        if(idx1 == 0 && idx2 == 0) return dp[idx1][idx2] = true;
        if(idx1 == 0 && idx2 > 0){
            for(int i = 0; i < idx2; i++){
                if(p[i] != '*') return dp[idx1][idx2] = false;
            }
            return dp[idx1][idx2] = true;
        }
        if(idx1 > 0 && idx2 == 0){
            return dp[idx1][idx2] = false;
        }
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s[idx1-1] == p[idx2-1] || p[idx2-1] == '?') return dp[idx1][idx2] = f(idx1-1, idx2-1, s, p, dp);
        if(p[idx2-1] == '*') return dp[idx1][idx2] = f(idx1-1, idx2, s, p, dp) || f(idx1, idx2-1, s, p,dp);
        return dp[idx1][idx2] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return f(n, m, s, p, dp);
    }
};