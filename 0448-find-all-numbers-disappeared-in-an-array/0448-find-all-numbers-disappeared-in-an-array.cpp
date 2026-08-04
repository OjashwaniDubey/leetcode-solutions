class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        for(int i = 1; i <= n; i++){
            if(freq[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};