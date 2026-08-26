class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int left = 0;
        int ones = 0;
        for(int right = 0; right < n; right++){
            if(s[right] == '1') ones++;
            while(ones == k){
                string cur = s.substr(left, right - left + 1);
                if(ans == "" || cur.size() < ans.size() || (cur.size() == ans.size() && cur < ans)){
                    ans = cur;
                }
                if(s[left] == '1') ones--;
                left++;
            }
        }
        return ans;
    }
};