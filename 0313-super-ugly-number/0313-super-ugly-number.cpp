class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();

        vector<int> mul(n);
        mul[0] = 1;

        vector<int> idx(m, 0);

        for(int i = 1; i < n; i++) {

            long long next = LLONG_MAX;

            // Find smallest candidate
            for(int j = 0; j < m; j++) {
                next = min(next,
                           1LL * mul[idx[j]] * primes[j]);
            }

            mul[i] = (int)next;

            // Move every pointer that produced next
            for(int j = 0; j < m; j++) {
                if(1LL * mul[idx[j]] * primes[j] == next) {
                    idx[j]++;
                }
            }
        }

        return mul[n - 1];
    }
};