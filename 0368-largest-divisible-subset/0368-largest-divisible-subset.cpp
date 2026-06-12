class Solution {
public:
    int f(int idx, int prev_idx, vector<int>& n1){
        int n = n1.size();
        if(idx == n) return 0;
        int len = f(idx+1, prev_idx, n1);
        if(prev_idx == -1 || n1[idx] % n1[prev_idx] == 0){
            len = max(len, 1 + f(idx+1, idx, n1));
        }
        return len;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 1;
        int lastIdx = 0;
        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int j = 0; j < i; j++){
                if(dp[j] + 1 > dp[i] && nums[i] % nums[j] == 0){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        vector<int> ans;
        while(hash[lastIdx] != lastIdx){
            ans.push_back(nums[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        ans.push_back(nums[lastIdx]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};