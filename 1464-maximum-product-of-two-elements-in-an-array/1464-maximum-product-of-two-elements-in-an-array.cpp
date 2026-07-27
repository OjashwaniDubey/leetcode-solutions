class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = -1e9;
        int max2 = -1e9;
        for(int x : nums){
            if(x >= max1){
                max2 = max1;
                max1 = x;
            }
            else if(x >= max2){
                max2 = x;
            }
        }
        return (max1-1)*(max2-1);
    }
};