class Solution {
public:
    bool f(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(i == s.size()) return true;
        if(j == t.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = f(i+1, j+1, s, t, dp) + f(i, j+1, s, t, dp);
        return dp[i][j] = f(i, j+1, s, t, dp);
    }
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n > m) return false;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, s, t, dp);
    }
};