class Solution {
public:
    int f(int idx1, int idx2, vector<int>& n1, vector<int>& n2, vector<vector<int>>& dp){
        if(idx1 == 0) return 0;
        if(idx2 == 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(n1[idx1-1] == n2[idx2-1]) return dp[idx1][idx2] = 1 + f(idx1-1, idx2-1, n1, n2, dp);
        return dp[idx1][idx2] = max(f(idx1-1, idx2, n1, n2, dp), f(idx1, idx2-1, n1, n2, dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return f(n, m, nums1, nums2, dp);
    }
};