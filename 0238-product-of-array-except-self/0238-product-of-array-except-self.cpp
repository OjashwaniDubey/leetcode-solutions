class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        int left = 1;
        int right = 1;
        for(int i = 0; i < n; i++){
            answer[i] = left;
            left *= nums[i];
        }
        for(int i = n-1; i >= 0; i--){
            answer[i] *= right;
            right *= nums[i];
        }
        return answer;
    }
};