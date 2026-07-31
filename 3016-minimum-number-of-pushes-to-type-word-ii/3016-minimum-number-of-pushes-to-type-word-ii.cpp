class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char, int> freq;
        int ans = 0;
        for(char c : word){
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it : freq){
            pq.push({it.second, it.first});
        }
        int i = 0;
        while(!pq.empty()){
            int num = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            ans += num * (i / 8 + 1);
            i++;
        }
        return ans;
    }
};