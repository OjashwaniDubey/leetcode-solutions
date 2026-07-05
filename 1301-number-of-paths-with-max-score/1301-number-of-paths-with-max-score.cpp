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
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
        auto ans = f(0, 0, board, dp);
        if(ans.first < 0) return {0,0};
        return {ans.first, ans.second};
    }
};