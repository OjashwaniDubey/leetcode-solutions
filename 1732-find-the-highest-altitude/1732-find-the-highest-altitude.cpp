class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0;
        int maxi = 0;
        for(int x : gain){
            curr += x;
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};