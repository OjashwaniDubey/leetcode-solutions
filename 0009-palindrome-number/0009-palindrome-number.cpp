class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        long long rev = 0;
        if(x < 0) return false;
        while(x > 0){
            int num = x % 10;
            rev = rev * 10 + num;
            x /= 10;
        }
        return (rev == original);
    }
};