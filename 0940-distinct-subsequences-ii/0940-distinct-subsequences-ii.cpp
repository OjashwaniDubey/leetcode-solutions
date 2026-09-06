class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> last(26, 0);

        long long dp = 0;

        for (char ch : s) {
            int c = ch - 'a';

            long long old = dp;

            long long take = old + 1;
            long long notTake = old;

            dp = (take + notTake - last[c] + MOD) % MOD;

            last[c] = take;
        }

        return dp;
    }
};