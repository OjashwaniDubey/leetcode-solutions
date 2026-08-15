class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for(int x : nums){
            len ^= x;
        }
        if(len != 0) return n;
        for(int num : nums){
            if(num != 0) return n-1;
        }
        return 0;
    }
};