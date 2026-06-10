class Solution {
public:
    int f(int idx, vector<int>& values, vector<int>& dp){
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = values[idx] + f(idx-2, values, dp);
        int notTake = f(idx-1, values, dp);
        return dp[idx] = max(take, notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> values(mx+1, 0);
        vector<int>dp(mx+1, 0);
        for(int x : nums){
            values[x] += x;
        }
        dp[0] = 0;
        if(mx >= 1) dp[1] = values[1];
        for(int i = 2; i <= mx; i++){
            dp[i] = max(values[i]+dp[i-2], dp[i-1]);
        }
        return dp[mx];
    }
};