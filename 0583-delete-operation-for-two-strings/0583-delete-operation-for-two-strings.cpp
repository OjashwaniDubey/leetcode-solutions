class Solution {
public:
    int f(int idx1, int idx2, string& s1, string& s2, vector<vector<int>>& dp){
        if(idx1 == 0) return idx2;
        if(idx2 == 0) return idx1;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1-1] == s2[idx2-1]) return dp[idx1][idx2] = f(idx1-1, idx2-1, s1, s2, dp);
        return dp[idx1][idx2] = 1 + min(f(idx1-1, idx2, s1, s2, dp), f(idx1, idx2-1, s1, s2, dp));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};