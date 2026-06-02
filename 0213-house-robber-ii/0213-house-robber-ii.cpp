class Solution {
public:
    int f(int index, int start, vector<int>& nums, vector<int> &dp){
        int n = nums.size();
        if(index == start) return nums[start];
        if(index == start + 1) return max(nums[start], nums[start + 1]);
        if(dp[index] != -1) return dp[index];
        //if(index == n-1) return max(nums[0], nums[n-1]);
        int notTake = f(index - 1, start, nums, dp);
        int take = nums[index] + f(index - 2, start, nums, dp);
        return dp[index] = max(notTake, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n, -1);
        vector<int> dp1(n-1, -1);
        int rob1 = f(n-2, 0, nums, dp1);
        int rob2 = f(n-1, 1, nums, dp);
        return max(rob1, rob2);
    }
};