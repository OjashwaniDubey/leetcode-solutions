class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int prefSum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1] + 1) prefSum += nums[i];
            else break;
        }
        int x = prefSum;
        while(find(nums.begin(), nums.end(), x) != nums.end()){
            x++;
        }
        return x;
    }
};