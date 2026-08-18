class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        long long sum = 0;
        long long ans = 0;
        unordered_map<int, int> freq;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            freq[nums[right]]++;
            if(right - left + 1 > k){
                freq[nums[left]]--;
                sum -= nums[left];
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
            if(right - left + 1 == k && freq.size() == k){
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};