class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<char, int> freq;
        unordered_map<string, int> mp;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < n; right++){
            freq[s[right]]++;
            if(right - left + 1 > minSize){
                freq[s[left]]--;
                if(freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
            if(right - left + 1 == minSize && freq.size() <= maxLetters){
                string sub = s.substr(left, minSize);
                mp[sub]++;
                ans = max(ans, mp[sub]);
            }
        }
        return ans;
    }
};