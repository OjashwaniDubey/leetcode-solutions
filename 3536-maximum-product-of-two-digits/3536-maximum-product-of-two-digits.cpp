class Solution {
public:
    int maxProduct(int n) {
        int max1 = -1;
        int max2 = -1;
        while(n){
            int x = n % 10;
            n /= 10;
            if(x >= max1){
                max2 = max1;
                max1 = x;
            }
            else if(x >= max2){
                max2 = x;
            }
        }
        return max1*max2;
    }
};