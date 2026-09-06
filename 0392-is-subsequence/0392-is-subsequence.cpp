class Solution {
public:
    bool f(int i, int j, string& s, string& t){
        if(i == s.size()) return true;
        if(j == t.size()) return false;
        if(s[i] == t[j]) return f(i+1, j+1, s, t) + f(i, j+1, s, t);
        return f(i, j+1, s, t);
    }
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n > m) return false;
        return f(0, 0, s, t);
    }
};