class Solution {
public:
    int f(int idx1, int idx2, string &s1, string &s2){
        if(idx1 == 0 || idx2 == 0) return 0;
        int ans = 0;
        if(s1[idx1] == s2[idx2]) ans = 1 + f(idx1-1, idx2-1, s1, s2);
        else ans = max(f(idx1-1, idx2, s1, s2), f(idx1, idx2-1, s1, s2));
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string result = "";
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                result += str1[i-1];
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                result += str1[i-1];
                i--;
            }
            else{
                result += str2[j-1];
                j--;
            }
        }
        while(i > 0){
            result += str1[i-1];
            i--;
        }
        while(j > 0){
            result += str2[j-1];
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};