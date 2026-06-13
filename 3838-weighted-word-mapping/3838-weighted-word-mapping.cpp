class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
       string ans;
       for(string &word : words){
        int wt = 0;
        for(char ch : word){
            wt += weights[ch-'a'];
        }
        int rem = wt % 26;
        ans.push_back('z'-rem);
       }
       return ans;
    }
};