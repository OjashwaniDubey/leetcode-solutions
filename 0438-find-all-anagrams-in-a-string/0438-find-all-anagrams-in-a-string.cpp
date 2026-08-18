class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> freqP(26, 0);
        vector<int> freqWindow(26, 0);
        for(char c : p){
            freqP[c-'a']++;
        }
        int left = 0;
        vector<int> ans;
        for(int right = 0; right < n; right++){
            freqWindow[s[right]-'a']++;
            if(right - left + 1 > m){
                freqWindow[s[left]-'a']--;
                left++;
            }
            if(right - left + 1 == m && freqWindow == freqP){
                ans.push_back(left);
            }
        }
        return ans;
    }
};