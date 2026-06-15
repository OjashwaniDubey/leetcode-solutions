class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
       if(a[0] == b[0]) return a[1] > b[1];
      return a[0] < b[0];
    }
    //int maxi = 0;
    //int lastIdx = 0;
    int maxEnvelopes(vector<vector<int>>& envelopes) {
    //    int n = envelopes.size();
          sort(envelopes.begin(), envelopes.end(), comp);
    //    vector<int>heights;
    //    for(auto &enve : envelopes){
    //        heights.push_back(enve[1]);
    //    }
    //    vector<int> dp(n, 1);
    //    vector<int> hash(n, 1);
    //    for(int i = 0; i < n; i++){
    //        for(int j = 0; j < i; j++){
    //            if(heights[i] > heights[j] && dp[j] + 1 > dp[i]){
    //                dp[i] = dp[j] + 1;
    //                hash[i] = i; 
    //            }
    //            if(dp[i] > maxi){
    //            maxi = dp[i];
    //            lastIdx = j;
    //          }
    //        }
    //    }
    //    return maxi;
          vector<int>temp;
          int len = 1;
          temp.push_back(envelopes[0][1]);
          for(int i = 1; i < envelopes.size(); i++){
            if(envelopes[i][1] > temp.back()){
                temp.push_back(envelopes[i][1]);
                len++;
            }
            else{
                auto idx = lower_bound(temp.begin(), temp.end(), envelopes[i][1]);
                *idx = envelopes[i][1];
            }
          }
          return temp.size();
    }
};