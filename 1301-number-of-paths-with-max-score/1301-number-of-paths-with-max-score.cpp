class Solution {
public:
    pair<int, int> f(int idx1, int idx2, vector<string>& board, vector<vector<pair<int, int>>>& dp){
        int n = board.size();
        const int N = -1e9;
        const int MOD = 1e9 + 7;
        if(idx1 >= n || idx2 >= n) return {N, 0};
        if(board[idx1][idx2] == 'X') return {N, 0};
        if(board[idx1][idx2] == 'S') return {0, 1};
        if(dp[idx1][idx2] != make_pair(-1, -1)) return dp[idx1][idx2];
        auto down = f(idx1+1, idx2, board, dp);
        auto right = f(idx1, idx2+1, board, dp);
        auto diag = f(idx1+1, idx2+1, board, dp);
        int best = max({down.first, right.first, diag.first});
        if(best == N) return dp[idx1][idx2] = {N, 0};
        long long ways = 0;
        if(best == down.first) ways += down.second;
        if(best == right.first) ways += right.second;
        if(best == diag.first) ways += diag.second;
        ways %= MOD;
        int val = 0;
        if(board[idx1][idx2] != 'E'){
            val = board[idx1][idx2]-'0';
        }
        return dp[idx1][idx2] = {best+val, (int)ways};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int N = -1e9;
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(n+1, {N, 0}));
        dp[n-1][n-1] = {0, 1};
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(board[i][j] == 'X') continue;
                if(board[i][j] == 'S') continue;
                auto down = dp[i+1][j];
                auto right = dp[i][j+1];
                auto diag = dp[i+1][j+1];
                int best = max({down.first, right.first, diag.first});
                if(best == N){
                    dp[i][j] = {N, 0};
                    continue;
                }
                long long ways = 0;
                if(best == down.first) ways += down.second;
                if(best == right.first) ways += right.second;
                if(best == diag.first) ways += diag.second;
                ways %= MOD;
                int val = 0;
                if(board[i][j] != 'E'){
                val = board[i][j]-'0';
              }
            dp[i][j] = {best+val, (int)ways};
            }
        }
        if(dp[0][0].first < 0){
            return {0,0};
        }
        return {dp[0][0].first, dp[0][0].second};
    }
};