class Solution {
public:
    string minWindow(string s, string t) {

        int m = s.size();
        int n = t.size();

        if(m < n) return "";

        int left = 0;
        int have = 0;

        int bestStart = 0;
        int bestLen = INT_MAX;

        unordered_map<char, int> need, window;

        for(char c : t){
            need[c]++;
        }

        for(int right = 0; right < m; right++){

            // Add s[right]
            window[s[right]]++;

            // Required frequency is satisfied
            if(need.count(s[right]) &&
               window[s[right]] == need[s[right]])
            {
                have++;
            }

            // Window is valid -> shrink
            while(have == need.size()){

                int len = right - left + 1;

                // Save only indices, NOT the substring
                if(len < bestLen){
                    bestLen = len;
                    bestStart = left;
                }

                // Remove s[left]
                window[s[left]]--;

                // Did removing it make window invalid?
                if(need.count(s[left]) &&
                   window[s[left]] < need[s[left]])
                {
                    have--;
                }

                left++;
            }
        }

        if(bestLen == INT_MAX)
            return "";

        return s.substr(bestStart, bestLen);
    }
};