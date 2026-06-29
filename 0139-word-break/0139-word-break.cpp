class Solution {
public:
    bool matchDict(string &t, vector<string>& wordDict){
        for(string &word : wordDict){
            if(t == word) return true;
        }
        return false;
    }
    bool f(int idx, string s, vector<string>& wordDict, vector<int>& dp){
        int n = s.size();
        if(idx == n) return true;
        if(dp[idx] != -1) return dp[idx];
        string temp = "";
        for(int j = idx; j < n; j++){
            temp += s[j];
            if(matchDict(temp, wordDict)){
                if(f(j+1, s, wordDict, dp)) return true; 
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        dp[n] = true;
        for(int idx = n-1; idx >= 0; idx--){
            string temp = "";
            for(int j = idx; j < n; j++){
                temp += s[j];
                if(matchDict(temp, wordDict)){
                    if(dp[j+1]){
                        dp[idx] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};