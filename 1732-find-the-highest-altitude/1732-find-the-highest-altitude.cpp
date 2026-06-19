class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> altitude(n+1, 0);
        for(int i = 0; i < n; i++){
            altitude[i+1] = altitude[i] + gain[i];           
        }
        int maxi = 0;
        for(int k : altitude){
            maxi = max(maxi, k);
        }
        return maxi;
    }
};