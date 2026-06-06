class Solution {
public:
    vector<int> f(int n, vector<int>& nums){
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> answer(n, 0);
        int totSum = 0;
        for(int i = 0; i < n; i++){
            totSum += nums[i];
        }
        for(int i = 0; i < n; i++){
            if(i == 0){
            left[0] = 0;
            right[0] = totSum - nums[0];
            answer[0] = abs(left[0] - right[0]);
        }
            left[i] = nums[i-1];
            right[i] = nums[i+1];
            answer[i] = abs(left[i] - right[i]);
        }
        return answer;
    }
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> answer(n, 0);
        for(int i = 1; i < n; i++){
            left[i] = nums[i-1] + left[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            right[i] = nums[i+1] + right[i+1];
        }
        for(int i = 0; i < n; i++){
            answer[i] = abs(left[i] - right[i]);
        }
        return answer;
    }
};