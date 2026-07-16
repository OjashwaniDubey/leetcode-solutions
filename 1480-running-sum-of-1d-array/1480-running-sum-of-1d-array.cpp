class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        int ele = nums[0];
        for(int i = 1; i < n; i++){
            ele += nums[i];
            ans.push_back(ele);
        }
        return ans;
    }
};