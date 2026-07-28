class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> mp;
        int ans = 0;
        for(string s : words){
            string rev = s;
            reverse(rev.begin(), rev.end());
            if(mp[rev] > 0){
                ans += 4;
                mp[rev]--;
            }
            else{
                mp[s]++;
            }
        }
        for(auto it : mp){
            string word = it.first;
            if(word[0] == word[1] && it.second > 0){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};