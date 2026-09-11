class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(vector<pair<int,int>>& freq, int i) {
        if (i == freq.size()) {
            ans.push_back(cur);
            return;
        }

        int num = freq[i].first;
        int count = freq[i].second;

        // Choose 0, 1, 2, ..., count copies
        for (int take = 0; take <= count; take++) {

            for (int j = 0; j < take; j++)
                cur.push_back(num);

            dfs(freq, i + 1);

            for (int j = 0; j < take; j++)
                cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        vector<pair<int,int>> freq(mp.begin(), mp.end());

        dfs(freq, 0);

        return ans;
    }
};