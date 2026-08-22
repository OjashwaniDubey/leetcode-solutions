class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int digitSum = 0;
        int digitProduct = 1;
        while(n != 0){
            int x = n % 10;
            digitSum += x;
            digitProduct *= x;
            n /= 10;
        }
        int i = digitSum + digitProduct;
        if(original % i == 0) return true;
        return false;  
    }
};