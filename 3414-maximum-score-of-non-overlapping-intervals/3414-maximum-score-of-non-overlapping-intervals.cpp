class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> indices;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices; // lexicographically smaller
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // [l, r, weight, originalIndex]
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by right endpoint.
        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[1] != y[1])
                return x[1] < y[1];

            return x[0] < y[0];
        });

        // ends[i] = right endpoint of sorted interval i
        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        /*
            prev[i] = number of intervals among [0 ... i-1]
                      whose right endpoint is < a[i][0].

            lower_bound gives the first end >= l.
            Therefore its position is exactly the number
            of valid previous intervals.
        */
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] = lower_bound(
                ends.begin(),
                ends.begin() + i,
                a[i][0]
            ) - ends.begin();
        }

        // dp[i][k] = best result using first i intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = 1; i <= n; i++) {
            int idx = i - 1;

            for (int k = 1; k <= 4; k++) {

                // Option 1: don't take this interval.
                State skip = dp[i - 1][k];

                // Option 2: take this interval.
                State take = dp[prev[idx]][k - 1];

                take.score += a[idx][2];
                take.indices.push_back((int)a[idx][3]);

                // The final answer must be compared by
                // original interval indices, not sorted order.
                sort(take.indices.begin(), take.indices.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[n][4].indices;
    }
};