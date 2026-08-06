class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro = 1;
        int sum = 0;
        int temp = n;
        while(temp){
            pro *= temp % 10;
            sum += temp % 10;
            temp /= 10;
        }
        return pro - sum;
    }
};