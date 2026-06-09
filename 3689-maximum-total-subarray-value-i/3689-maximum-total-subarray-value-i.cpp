class Solution {
public:
    long long f(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> n1; 
        long long maxi = *max_element(nums.begin(), nums.end());
        long long mini = *min_element(nums.begin(), nums.end());
        long long sum = 0;
        if(k == 1){
            return maxi - mini;
        }
        for(int i = 1; i <= k; i++){
            sum += (maxi - mini);
        }
        return sum;
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        return f(nums, k);
    }
};