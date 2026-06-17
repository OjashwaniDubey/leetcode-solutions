class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.size();
        long long len = 0;
        for(char c : s){
            if(isdigit(c)){
                len *= (c - '0');
            }
            else{
                len++;
            }
        }
        for(int i = n-1; i >= 0; i--){
            k %= len;
            if(k == 0 && isalpha(s[i])){
                return string(1, s[i]);
            }
            if(isdigit(s[i])){
                len /= (s[i] - '0');
            }
            else{
                len--;
            }
        }
        return "";
    }
};