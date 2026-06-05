class Solution {
public:
    int f(int idx1, int idx2, string& s1, string& s2, vector<vector<int>>& dp){
        if(idx1 == 0 || idx2 == 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1-1] == s2[idx2-1]) dp[idx1][idx2] = 1 + f(idx1-1, idx2-1, s1, s2, dp);
        else dp[idx1][idx2] = max(f(idx1-1, idx2, s1, s2, dp), f(idx1, idx2-1, s1, s2, dp));
        return dp[idx1][idx2]; 
    }
    int palinf(string& s){
        string t = s;
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        reverse(t.begin(), t.end());
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= n; j++) dp[0][j] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        int n = s.size();
        return n-palinf(s);
    }
};