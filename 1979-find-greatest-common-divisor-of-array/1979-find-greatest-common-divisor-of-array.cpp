class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int start = nums[0];
        int end = nums[n-1];
        return gcd(start, end);
    }
};