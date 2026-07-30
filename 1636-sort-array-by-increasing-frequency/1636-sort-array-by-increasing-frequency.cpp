class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        for(auto it : freq){
            pq.push({-it.second, it.first});
        }
        int idx = 0;
        while(!pq.empty()){
            int count = -pq.top().first;
            int digit = pq.top().second;
            pq.pop();
            for(int i = 0; i < count; i++){
                nums[idx++] = digit;
            }
        }
        return nums;
    }
};