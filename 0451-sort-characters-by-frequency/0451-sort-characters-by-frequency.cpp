class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        string ans = "";
        priority_queue<pair<int, char>> pq;
        for(char c : s){
            freq[c]++;
        }
        for(auto it : freq){
            pq.push({it.second, it.first});
        }
        while(!pq.empty()){
            int fr = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            for(int i = 0; i < fr; i++){
                ans += ch;
            }
        }
        return ans;
    }
};