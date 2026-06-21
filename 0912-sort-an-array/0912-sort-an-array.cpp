class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        vector<int>freq(maxi-mini+1, 0);
        for(int i : nums){
            freq[i-mini]++;
        }
        vector<int>ans;
        for(int i = 0; i < freq.size(); i++){
            while(freq[i] > 0){
                ans.push_back(i+mini);
                freq[i]--;
            }
        }
        return ans;
    }
};