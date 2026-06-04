class Solution {
public:
    int f(int idx1, int idx2, string s1, string s2, vector<vector<int>>& dp){
        if(idx1 == 0 || idx2 == 0){
            return 0;
        }
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1-1] == s2[idx2-1]){
            dp[idx1][idx2] = 1 + f(idx1-1, idx2-1, s1, s2, dp);
        }
        else dp[idx1][idx2] = max(f(idx1-1, idx2, s1, s2, dp), f(idx1, idx2-1, s1, s2, dp));
        return dp[idx1][idx2];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
        for(int i = 0; i <= n1; i++) dp[i][0] = 0;
        for(int j = 0; j <= n2; j++) dp[0][j] = 0;
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};