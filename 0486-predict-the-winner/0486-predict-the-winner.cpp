class Solution {
public:
    int f(int i, int j, vector<int>& nums){
        if(i == j) return nums[i];
        int takeLeft = nums[i] - f(i+1, j, nums);
        int takeRight = nums[j] - f(i, j-1, nums);
        return max(takeLeft, takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return f(0, n-1, nums) >= 0;
    }
};