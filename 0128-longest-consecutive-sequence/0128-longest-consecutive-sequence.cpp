class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(int x : st){
            if(st.find(x-1) == st.end()){
                int current = x;
                while(st.find(current+1) != st.end()){
                    current++;
                }
                int length = current - x + 1;
                ans = max(ans, length);
            }
        }
        return ans;
    }
};