class Solution {
public:
    int f(int idx1, int idx2, string s1, string s2, vector<vector<int>>& dp){
        if(idx1 == 0 || idx2 == 0) return 0;
        int ans = 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1-1] == s2[idx2-1]) ans = 1 + f(idx1-1, idx2-1, s1, s2, dp);
        else ans = max(f(idx1-1, idx2, s1, s2, dp), f(idx1, idx2-1, s1, s2, dp));
        return dp[idx1][idx2] = ans;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(s.empty()) return "";
        int start = 0;
        int maxLen = 1;
        for(int i = 0; i < n; i++){
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                int len = r - l + 1;
                if(len > maxLen){
                    maxLen = len;
                    start = l;
                }
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                int len = r - l + 1;
                if(len > maxLen){
                    maxLen = len;
                    start = l;
                }
                l--;
                r++;
            } 
        }
        return s.substr(start, maxLen);
    }
};