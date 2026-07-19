class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> vis(26, false);

        // Count frequencies
        for (char c : s)
            freq[c - 'a']++;

        stack<char> st;

        for (char c : s) {
            // Current character is being processed
            freq[c - 'a']--;

            // Already included in answer
            if (vis[c - 'a'])
                continue;

            // Remove larger characters if they appear later
            while (!st.empty() &&
                   st.top() > c &&
                   freq[st.top() - 'a'] > 0) {

                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            vis[c - 'a'] = true;
        }

        // Build answer
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};