class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1;
        long long start = 1;
        long long count = 9;
        while(n > digits * count){
            n -= digits * count;
            digits++;
            start *= 10;
            count *= 10;
        }
        long long num = start + (n - 1)/ digits;
        int index = (n-1) % digits;
        string s = to_string(num);
        return s[index] - '0';
    }
};