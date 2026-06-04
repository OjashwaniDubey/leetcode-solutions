class Solution {
public:
    int f(int index1, int index2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(index1 == 0 || index2 == 0) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if(nums1[index1 - 1] == nums2[index2 - 1]){
            dp[index1][index2] = 1 + f(index1-1, index2-1, nums1, nums2, dp);
        }
        else dp[index1][index2] = 0;
        return dp[index1][index2];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
        for(int j = 0; j <= n2; j++){
            dp[0][j] = 0;
        }
        for(int i = 0; i <= n1; i++){
            dp[i][0] = 0;
        }
        int len = 0;
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = 0;
                len = max(len, dp[i][j]);
            }
        }
        return len;
    }
};