class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1e9;
        int max2 = -1e9;
        int max3 = -1e9;
        int min1 = 1e9;
        int min2 = 1e9;
        for(int x : nums){
            if(x >= max1){
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if(x >= max2){
                max3 = max2;
                max2 = x;
            }
            else if(x >= max3){
                max3 = x;
            }
            if(x <= min1){
                min2 = min1;
                min1 = x;
            }
            else if(x <= min2){
                min2 = x;
            }
        }
        return max(max1*max2*max3, min1*min2*max1);
    }
};