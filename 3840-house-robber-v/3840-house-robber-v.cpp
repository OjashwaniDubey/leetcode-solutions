class Solution {
public:
    long long f(int idx, int prevRobbedIdx, vector<int>& nums, vector<int>& colors, vector<vector<long long>>& dp){
        int n = nums.size();
        if(idx == n) return 0;
        int mobIdx = prevRobbedIdx + 1;
        if(dp[idx][mobIdx] != -1) return dp[idx][mobIdx];
        long long skip = f(idx+1, prevRobbedIdx, nums, colors, dp);
        long long rob = 0;
        bool canRob = false;
        if((idx - prevRobbedIdx) > 1) canRob = true;
        else if(prevRobbedIdx == -1) canRob = true;
        else if((idx - prevRobbedIdx) == 1 && colors[idx] != colors[prevRobbedIdx]) canRob = true;
        if(canRob) rob = nums[idx] + f(idx+1, idx, nums, colors, dp);
        return dp[idx][mobIdx] = max(skip, rob);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        //int n = nums.size();
        //vector<long long> curr(n+1, 0);
        //vector<long long> next(n+1, 0);
        //if(n == 0) return 0;
        //for(int i = n-1; i >= 0; i--){
        //    for(int j = 0; j <= n; j++){
        //        long long prevRobbedIdx = j-1;
        //        long long robHouse = 0;
        //        bool canRob = false;
        //        long long skip = next[j];
        //        if(prevRobbedIdx == -1) canRob = true;
        //        else if(i - prevRobbedIdx == 1 && colors[i] != colors[prevRobbedIdx]) canRob = true;
        //        else if(i - prevRobbedIdx > 1) canRob = true;
        //        if(canRob) robHouse = nums[i] + next[i+1];
        //        curr[j] = max(robHouse, skip);
        //    }
        //   next = curr;
        //}
        //return next[0];
        int n = nums.size();
        vector<long long>dp(n);
        if(n == 1) return nums[0];
        dp[0] = nums[0];
        if(colors[0] != colors[1]) dp[1] = nums[0] + nums[1];
        else dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            long long skip = dp[i-1];
            long long take = 0;
            if(colors[i] != colors[i-1]) take = nums[i] + dp[i-1];
            else take = nums[i] + dp[i-2];
            dp[i] = max(take, skip);
        }
        return dp[n-1];
    }
};