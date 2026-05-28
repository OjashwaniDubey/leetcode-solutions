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
        return dp[index][target] = take | notTake;
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
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(nums, n-1, target, dp);
    }
};