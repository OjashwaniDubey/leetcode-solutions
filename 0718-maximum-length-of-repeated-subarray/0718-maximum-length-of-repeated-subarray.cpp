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
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        int len = 0;
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                len = max(len, f(i, j, nums1, nums2, dp));
            }
        }
        return len;
    }
};