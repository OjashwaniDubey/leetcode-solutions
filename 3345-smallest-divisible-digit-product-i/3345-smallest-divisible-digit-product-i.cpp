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
        while(true){
        int product = 1;
        int temp = n;
        while(temp){
            product *= temp % 10;
            temp /= 10;
        }
        if(product % t == 0) return n;
        n++;
        }
    }
};