class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;
        unordered_map<int, int>m;
        for(int el : nums){
            m[el]++;
        }
        for(auto p : m){
            pq.push({p.second, p.first});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++){
            auto [freq, val] = pq.top();
            pq.pop();
            ans.push_back(val);
        }
        return ans;
    }
};