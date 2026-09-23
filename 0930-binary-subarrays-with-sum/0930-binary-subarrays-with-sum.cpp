class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int prefixSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        for(int x : nums){
            prefixSum += x;
            if(mp.count(prefixSum-goal)){
                ans += mp[prefixSum-goal];
            }
            mp[prefixSum]++;
        }
        return ans;
    }
};