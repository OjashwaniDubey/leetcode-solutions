class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n){
            int x = n % 10;
            n /= 10;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        int m = arr.size();
        return arr[m-1]*arr[m-2];
    }
};