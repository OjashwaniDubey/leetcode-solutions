class Solution {
public:
    const long long LIMIT = 1000001;

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long ans = 1;
        int used = 0;

        for (int f : cnt) {
            for (int i = 1; i <= f; i++) {
                ans = ans * (used + i) / i;
                if (ans > LIMIT) ans = LIMIT;
            }
            used += f;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string middle = "";

        vector<int> half(26);

        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2)
                middle.push_back(char('a' + i));

            half[i] = freq[i] / 2;
        }

        if (countWays(half) < k)
            return "";

        string left = "";

        int len = 0;
        for (int x : half)
            len += x;

        while (len--) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {

                    left.push_back(char('a' + c));
                    break;

                } else {

                    k -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};