class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> freqs1(26, 0);
        vector<int> freqs2(26, 0);
        if(n > m) return false;
        for(char c : s1){
            freqs1[c-'a']++;
        }
        int left = 0;
        for(int right = 0; right < m; right++){
            freqs2[s2[right]-'a']++;
            if(right - left + 1 > n){
                freqs2[s2[left]-'a']--;
                left++;
            }
            if(right - left + 1 == n && freqs1 == freqs2){
                return true;
            }
        }
        return false;
    }
};