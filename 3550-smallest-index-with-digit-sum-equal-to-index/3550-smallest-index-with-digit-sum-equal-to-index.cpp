class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int x : nums){
            int sum = 0;
            while(x){
                int num = x % 10;
                sum += num;
                x /= 10;
            }
            ans.push_back(sum);
        }
        for(int i = 0; i < n; i++){
            if(i == ans[i]) return i;
        }
        return -1;
    }
};