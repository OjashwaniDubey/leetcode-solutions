class Solution {
public:
    int f(int i, vector<int>& arr, vector<int>& dp){
        int n = arr.size();
        if( i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int take1 = arr[i] - f(i+1, arr, dp);
        int take2 = INT_MIN;
        if(i + 1 < n) take2 = arr[i] + arr[i+1] - f(i+2, arr, dp);
        int take3 = INT_MIN; 
        if(i + 2 < n) take3 = arr[i] + arr[i+1] + arr[i+2] - f(i+3, arr, dp);
        return dp[i] = max(take1, max(take2, take3));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1);
        int score = f(0, stoneValue, dp);
        if(score > 0) return "Alice";
        else if(score < 0) return "Bob";
        else return "Tie";
    }
};