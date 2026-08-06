class Solution {
public:
    int f(int n, int t){
        int temp = n;
        int pro = 1;
        while(temp){
            pro *= temp % 10;
            temp /= 10;
        }
        if(pro % t == 0) return n;
        return f(n+1, t);
    }
    int smallestNumber(int n, int t) {
        return f(n, t);
    }
};