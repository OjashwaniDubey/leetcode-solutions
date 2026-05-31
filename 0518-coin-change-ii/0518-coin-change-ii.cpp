class Solution {
public:
    int f(int index, int amount, vector<int>& coins, vector<vector<int>> &dp){
        int n = coins.size();
        if(index == 0){
            if(amount  % coins[0] == 0){
                return 1;
            }
            else return 0;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int notPick = f(index-1, amount, coins, dp);
        int pick = 0;
        if(coins[index] <= amount){
            pick = f(index, amount-coins[index], coins, dp);
        }
        return dp[index][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int combinations = f(n-1, amount, coins, dp);
        return combinations;
    }
};