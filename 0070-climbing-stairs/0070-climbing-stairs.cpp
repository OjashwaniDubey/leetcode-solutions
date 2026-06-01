class Solution {
public:
    int climbStairs(int n) {
//        vector<int> memo(n+1, -1);
//        return helper(n, memo);
          if( n <= 1) return 1;
          int prev1 = 1, prev2 = 1;
          for(int i = 2; i <= n; ++i){
          int curr = prev1 + prev2;
          prev2 = prev1;
          prev1 = curr;
          }
          return prev1;
    }
//private:
//    int helper(int n, vector<int> &memo){
//        if(n <= 1){
//            return 1;
//        }
//        if(memo[n] != -1){
//            return memo[n];
//        }
//        memo[n] = helper(n-1, memo) + helper(n-2, memo);
//        return memo[n];
//    }
};