class Solution {
public:
    bool f(vector<int>& nums, int index, int target, vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }
        if(index == 0){
            return nums[0] == target;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        bool notTake = f(nums, index-1, target, dp);
        bool take = false;
        if(nums[index] <= target){
            take = f(nums, index-1, target-nums[index], dp);
        }
        return dp[index][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        if(totalSum % 2 != 0){
            return false;
        } 
        int target = totalSum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        if(nums[0] <= target){
            dp[0][nums[0]] = true;
        }
        for(int i = 1; i < n; i++){
            for(int  j = 1; j <= target; j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(nums[i] <= j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take || notTake;
            }
        }
        return dp[n-1][target];
    }
};