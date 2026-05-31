class Solution {
public:
    int f(int index, int n, vector<int>& coins, int amount, vector<vector<int>> &dp){
        if(index == 0){
            if(amount % coins[0] == 0){
                return amount / coins[index];
            }
            else{
                return 1e9;
            }
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int notPick = f(index-1, n, coins, amount, dp);
        int pick = 1e9;
        if(coins[index] <= amount){
            pick = 1 + f(index, n, coins, amount-coins[index], dp);
        }
        return dp[index][amount] = min(notPick, pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }
            else dp[0][i] = 1e9;
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                int notPick = dp[i-1][j];
                int pick = 1e9;
                if(coins[i] <= j){
                    pick = 1 + dp[i][j-coins[i]];
                }
                dp[i][j] = min(notPick, pick);
            }
        }
        int totalCoins = dp[n-1][amount];
        if(totalCoins >= 1e9){
            return -1;
        }
        return totalCoins;
    }
};