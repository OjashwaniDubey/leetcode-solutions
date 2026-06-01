class Solution {
public:
    int f(int index, int target, vector<int>& nums){
        if(index == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }
        int notTake = f(index-1, target, nums);
        int take = 0;
        if(nums[index] <= target){
            take = f(index-1, target-nums[index], nums);
        }
        return take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        if((totalSum - target) < 0 || (totalSum - target) % 2) return 0;
        return f(n-1, (totalSum - target) / 2, nums);
    }
};