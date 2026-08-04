class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        for(int x = 1; ; x++){
            if(st.find(x) == st.end()) return x;
        }
        return 0;
    }
};