class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int num : nums){
            x ^= num;
        }
        return x;
    }
};