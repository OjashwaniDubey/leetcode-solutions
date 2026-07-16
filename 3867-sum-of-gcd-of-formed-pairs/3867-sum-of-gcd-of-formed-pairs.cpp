class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGCD(n);
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            prefixGCD[i] = gcd(nums[i], mx);
        }
        sort(prefixGCD.begin(), prefixGCD.end());
        long long ans = 0;
        int start = 0;
        int end = n-1;
        while(start < end){
            ans += gcd(prefixGCD[start], prefixGCD[end]);
            start++;
            end--;
        }
        return ans;
    }
};