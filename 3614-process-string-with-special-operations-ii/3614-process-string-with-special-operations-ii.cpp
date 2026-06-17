class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        //string result;
        //for(char ch : s){
        //    if(ch == '*'){
        //        if(!result.empty()){
        //            result.pop_back();
        //        }
        //    }
        //    else if(ch == '#'){
        //        result.append(result);
        //    }
        //    else if(ch == '%'){
        //        reverse(result.begin(), result.end());
        //    }
        //    else{
        //        result.push_back(ch);
        //    }
        //}
        //return result.size() <= k ? '.' : result[k];
        vector<long long>len(n+1, 0);
        for(int i = 0; i < n; i++){
            len[i+1] = len[i];
            if('a' <= s[i] && s[i] <= 'z'){
                len[i+1]++;
            }
            else if(s[i] == '*'){
                if(len[i+1] > 0) len[i+1]--;
            }
            else if(s[i] == '#'){
                len[i+1] *= 2;
            }
        }
        if(k >= len[n]) return '.';
        for(int i = n-1; i >= 0; i--){
            if(isalpha(s[i])){
                if(k == len[i])  return s[i];
            }
            else if(s[i] == '#'){
                long long oldLen = len[i];
                if(k >= oldLen){
                    k -= oldLen;
                }
            }
            else if(s[i] == '%'){
                    k = len[i] - k - 1;
            }
        }
        return '.';
    }
};