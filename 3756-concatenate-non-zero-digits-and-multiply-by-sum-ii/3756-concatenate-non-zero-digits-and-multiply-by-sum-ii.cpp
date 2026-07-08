class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> digit, pos;
    vector<long long> prefSum, prefNum, pow10;
    void buildDigitAndPos(string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                digit.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }
    }
    void buildPrefixSum(string &s) {
        int n = s.size();
        prefSum.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i];

            if (s[i] != '0')
                prefSum[i + 1] += s[i] - '0';
        }
    }
    void buildPow10() {
        int k = digit.size();

        pow10.assign(k + 1, 1);

        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;
    }
    void buildPrefixNumber() {
        int k = digit.size();

        prefNum.assign(k + 1, 0);

        for (int i = 1; i <= k; i++) {
            prefNum[i] =
            (
                prefNum[i - 1] * 10
                + digit[i - 1]
            ) % MOD;
        }
    }
    long long getNumber(int L, int R) {
        int len = R - L + 1;

        return (
            prefNum[R + 1]
            - prefNum[L] * pow10[len] % MOD
            + MOD
        ) % MOD;
    }
    long long getDigitSum(int l, int r) {
        return prefSum[r + 1] - prefSum[l];
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        buildDigitAndPos(s);
        buildPrefixSum(s);
        buildPow10();
        buildPrefixNumber();

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            auto left = lower_bound(pos.begin(), pos.end(), l);
            auto right = upper_bound(pos.begin(), pos.end(), r);

            if (left == right) {
                ans.push_back(0);
                continue;
            }

            right--;

            int L = left - pos.begin();
            int R = right - pos.begin();

            long long x = getNumber(L, R);
            long long sum = getDigitSum(l, r);

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};