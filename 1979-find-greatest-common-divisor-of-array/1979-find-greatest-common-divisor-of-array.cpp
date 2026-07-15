class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int mn = nums[0];
        for(int x : nums){
            mx = max(mx, x);
            mn = min(mn, x);
        }
        return gcd(mx, mn);
    }
};