class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long totalSum = 0;
        for(int x : nums){
            totalSum += x;
        }
        if(totalSum < x) return -1;
        if(totalSum == x) return n;
        long long target = totalSum - x;
        int left = 0;
        long long sum = 0;
        int maxLen = -1;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            while(left <= right && sum > target){
                sum -= nums[left];
                left++;
            }
            if(sum == target) maxLen = max(maxLen, right-left+1);
        }
        if(maxLen == -1) return -1;
        return n - maxLen;
    }
};