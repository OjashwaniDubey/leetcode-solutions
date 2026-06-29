class Solution {
public:
    bool isPalindrome(string& t){
        int i = 0;
        int j = t.size()-1;
        while(i < j){
            if(t[i] != t[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int idx, string& s, vector<int>& dp){
        int n = s.size();
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        string temp = "";
        int minCuts = 1e9;
        for(int j = idx; j < n; j++){
            temp += s[j];
            if(isPalindrome(temp)){
                minCuts = min(minCuts, 1 + f(j+1, s, dp));
            }
        }
        return dp[idx] = minCuts;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        dp[n] = 0;
        for(int idx = n-1; idx >= 0; idx--){
            int minCuts = 1e9;
            string temp = "";
            for(int j = idx; j < n; j++){
            temp += s[j];
            if(isPalindrome(temp)){
                minCuts = min(minCuts, 1 + dp[j+1]);
            }
            }
            dp[idx] = minCuts;
        }
        return dp[0]-1;
    }
};