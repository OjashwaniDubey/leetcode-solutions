class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int left = 0;
        vector<int>freq1(26, 0);
        vector<int>freq2(26, 0);
        for(int i = 0; i < n; i++){
            freq2[s1[i]-'a']++;
        }
        for(int right = 0; right < m; right++){
            freq1[s2[right]-'a']++;
            if(right-left+1 == n){
                if(freq1 == freq2) return true;
                else{
                    freq1[s2[left]-'a']--;
                    left++;
                }
            }
        }
        return false;
    }
};