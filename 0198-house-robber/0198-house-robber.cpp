class Solution {
public:
    int f(int index, vector<int>& nums, vector<int>& dp){
        if(index == 0){
            return nums[0];
        }
        if(index == 1) return max(nums[0],nums[1]);
        if(dp[index] != -1) return dp[index];
        int notTake = f(index-1, nums, dp);
        int take = nums[index] + f(index-2, nums, dp);
        return dp[index] = max(notTake, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
    }
};