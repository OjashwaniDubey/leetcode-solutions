class Solution {
public:
    static const long long MOD = 1000000007;

    vector<vector<long long>> multiply(
        vector<vector<long long>>& A,
        vector<vector<long long>>& B
    ) {
        int n = A.size();
        vector<vector<long long>> C(n, vector<long long>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int k = 0; k < n; k++) {
                if(A[i][k] == 0) continue;

                for(int j = 0; j < n; j++) {
                    if(B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] +
                              A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<vector<long long>> power(
        vector<vector<long long>> base,
        long long exp
    ) {
        int n = base.size();

        vector<vector<long long>> res(
            n,
            vector<long long>(n, 0)
        );

        for(int i = 0; i < n; i++)
            res[i][i] = 1;

        while(exp) {
            if(exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if(n == 1)
            return m;

        int states = 2 * m;

        auto id = [&](int val, int dir) {
            return 2 * val + dir;
        };

        vector<vector<long long>> T(
            states,
            vector<long long>(states, 0)
        );

        // Build transition matrix
        for(int v = 0; v < m; v++) {

            // dir = UP
            for(int nxt = 0; nxt < v; nxt++) {
                T[id(v,1)][id(nxt,0)] = 1;
            }

            // dir = DOWN
            for(int nxt = v + 1; nxt < m; nxt++) {
                T[id(v,0)][id(nxt,1)] = 1;
            }
        }

        vector<long long> start(states, 0);

        // Initialize all valid length-2 arrays
        for(int a = 0; a < m; a++) {
            for(int b = 0; b < m; b++) {

                if(a == b) continue;

                if(b > a)
                    start[id(b,1)]++;

                else
                    start[id(b,0)]++;
            }
        }

        if(n == 2) {
            long long ans = 0;
            for(long long x : start)
                ans = (ans + x) % MOD;
            return (int)ans;
        }

        vector<vector<long long>> P = power(T, n - 2);

        vector<long long> finalState(states, 0);

        for(int i = 0; i < states; i++) {
            for(int j = 0; j < states; j++) {
                finalState[j] =
                    (finalState[j] +
                     start[i] * P[i][j]) % MOD;
            }
        }

        long long ans = 0;

        for(long long x : finalState)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};