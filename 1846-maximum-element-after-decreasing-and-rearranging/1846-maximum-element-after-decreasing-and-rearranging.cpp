class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int cur = 1;
        for(int i = 1; i < n; i++){
            cur = min(arr[i], cur+1);
        }
        return cur;
    }
};