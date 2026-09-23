class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefixSum = 0;
        int ans = 0;
        for(int x : nums){
            prefixSum += x;
            if(mp.count(prefixSum-k)){
                ans += mp[prefixSum - k];
            }
            mp[prefixSum]++;
        }
        return ans;
    }
};