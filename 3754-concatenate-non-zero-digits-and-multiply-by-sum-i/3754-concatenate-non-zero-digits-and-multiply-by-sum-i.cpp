class Solution {
public:
    long long sumAndMultiply(int n) {
        //vector<int> arr;
        //while(n){
        //    int x = n%10;
        //    n /= 10;
        //    if(x != 0){
        //        arr.push_back(x);
        //    }
        //}
        //int sum = 0;
        //int x = 0;
        //reverse(arr.begin(), arr.end());
        //for(int num : arr){
        //    sum += num;
        //    x = x * 10 + num;
        //}
        //return (long long)x * sum;
        string s = to_string(n);
        long long x = 0;
        long long sum = 0;
        for(auto c : s){
            if(c != '0'){
                int num = c - '0';
                x = x * 10 + num;
                sum += num;
            }
        }
        return x * sum;
    }
};