class Solution {
public:
    long long f(int pos, int prev1, int dir, int l, int r, int n, vector<vector<vector<long long>>>& dp){
        if(pos == n) return 1;
        if(dp[pos][prev1][dir] != -1) return dp[pos][prev1][dir];
        long long ans = 0;
        const long long MOD = 1e9 + 7;
        for(int cur = l; cur <= r; cur++){
            if(dir == 1){
                if(cur >= prev1) continue;
                ans = (ans + f(pos+1, cur, 0, l, r, n, dp)) % MOD;
            }
            else{
                if(cur <= prev1) continue;
                ans = (ans + f(pos+1, cur, 1, l, r, n, dp)) % MOD;
            }
        }
        return dp[pos][prev1][dir] = ans;
    }
    int zigZagArrays(int n, int l, int r) {
        //vector<vector<vector<long long>>>dp(n, vector<vector<long long>>(r+1, vector<long long>(2, -1)));
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        int m = r-l+1;
        vector<long long>up(m+1);
        vector<long long>down(m+1);
        for(int i = 1; i <= m; i++){
            up[i] = i-1;
            down[i] = m-i;
        }
        vector<long long>pref(m+1, 0);
        vector<long long>suff(m+2, 0);
        vector<long long>newUp(m+1, 0);
        vector<long long>newDown(m+1, 0);
        for(int i = 1; i <= m; i++){
            newUp[i] = pref[i-1];
            newDown[i] = suff[i+1];
        }
        for(int len = 3; len <= n; len++){
            pref[0] = 0;
            for(int i = 1; i <= m; i++){
                pref[i] = (pref[i-1] + down[i]) % MOD;
            }
            suff[m+1] = 0;
            for(int i = m; i >= 1; i--){
                suff[i] = (suff[i+1] + up[i]) % MOD;
            }
            for(int i = 1; i <= m; i++){
                newUp[i] = pref[i-1];
                newDown[i] = suff[i+1];
            }
            up = newUp;
            down = newDown;
        }
        for(int i = 1; i <= m; i++){
            ans = (ans + down[i]) % MOD;
            ans = (ans + up[i]) % MOD;
        }
        return (int)ans;
    }
};