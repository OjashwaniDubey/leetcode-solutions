class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        string ans = "";
        priority_queue<pair<int, char>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        int prevFreq = 0;
        char prevChar = '#';
        while(!pq.empty()){
            int count = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            ans += ch;
            count--;
            if(prevFreq > 0){
                pq.push({prevFreq, prevChar});
            }
            prevFreq = count;
            prevChar = ch;
        }
        if(prevFreq > 0) return "";
        return ans;
    }
};