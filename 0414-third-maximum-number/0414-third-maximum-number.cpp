class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;
        for(int d : nums){
            if(d == max1 || d == max2 || d == max3) continue;
            if(d > max1){
                max3 = max2;
                max2 = max1;
                max1 = d;
            }
            else if(d > max2){
                max3 = max2;
                max2 = d;
            }
            else if(d > max3){
                max3 = d;
            }
        }
        return (max3 == LLONG_MIN) ? max1 : max3;
    }
};