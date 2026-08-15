class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int m = queries.size();
        int n = arr.size();
        vector<int>prefix(n+1, 0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] ^ arr[i];
        }
        vector<int> ans;
        for(int i = 0; i < m; i++){
            int L = queries[i][0];
            int R = queries[i][1];
            ans.push_back(prefix[R+1] ^ prefix[L]);
        }
        return ans;
    }
};