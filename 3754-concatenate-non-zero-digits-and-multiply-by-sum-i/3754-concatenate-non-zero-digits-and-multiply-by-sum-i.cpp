class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> arr;
        while(n){
            int x = n%10;
            n /= 10;
            if(x != 0){
                arr.push_back(x);
            }
        }
        int sum = 0;
        int x = 0;
        reverse(arr.begin(), arr.end());
        for(int num : arr){
            sum += num;
            x = x * 10 + num;
        }
        return (long long)x * sum;
    }
};