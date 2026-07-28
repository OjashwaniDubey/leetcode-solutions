class Solution {
public:
    int longestPalindrome(string s) {
        //vector<int> freq(52, 0);
        //string left = "";
        //string middle = "";
        //for(char c : s){
        //    if(islower(c)){
        //        freq[c-'a']++;
        //    }
        //    else freq[c-'A'+26]++;
        //}
        //for(int i = 0; i < 52; i++){
        //    char ch;
        //    if(i < 26){
        //        ch = 'a'+i;
        //    }
        //    else ch = 'A'+i-26;
        //    left.append(freq[i]/2, ch);
        //    if(freq[i]%2 && middle.empty()){
        //        middle = ch;
        //    }
        //}
        //string right = left;
        //reverse(right.begin(), right.end());
        //string ans = left + middle + right;
        //return ans.size();
        vector<int> freq(128, 0);
        int ans = 0;
        for(char c : s){
            freq[c]++;
        }
        bool odd = false;
        for(int x : freq){
            ans += (x/2)*2;
            if(x % 2) odd = true;
        }
        if(odd) ans++;
        return ans;
    }
};