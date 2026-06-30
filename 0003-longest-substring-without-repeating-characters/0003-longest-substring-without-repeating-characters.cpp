class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int ans = 0;
        vector<int>freq(128, 0);
        for(int right = 0; right < n; right++){
            freq[s[right]]++;
            while(freq[s[right]] == 2){
                freq[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};