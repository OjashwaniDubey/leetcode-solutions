class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int x = k;
        for(int num : nums){
            if(x == num) x += k;
            else if(num > x) return x;
        }
        return x;
    }
};