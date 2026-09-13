class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        //for(int dr = -(n-1); dr <= n-1; dr++){
        //    for(int dc = -(n-1); dc <= n-1; dc++){
        //        int overlap = 0;
        //        for(int i = 0; i < n; i++){
        //            for(int j = 0; j < n; j++){
        //                if(img1[i][j] == 1){
        //                    int newi = i + dr;
        //                    int newj = j + dc;
        //                    if(newi >= 0 && newi < n && newj >= 0 && newj < n){
        //                        if(img2[newi][newj] == 1) overlap++;
        //                    }
        //                }
        //            }
        //        }
        //        ans = max(ans, overlap);
        //    }
        //}
        //return ans;
        map<pair<int, int>, int> freq;
        for(int i1 = 0; i1 < n; i1++){
            for(int j1 = 0; j1 < n; j1++){
                if(img1[i1][j1] == 1){
                    for(int i2 = 0; i2 < n; i2++){
                        for(int j2 = 0; j2 < n; j2++){
                            if(img2[i2][j2] == 1){
                                int dr = i2-i1;
                                int dc = j2-j1;
                                freq[{dr, dc}]++;
                                ans = max(ans, freq[{dr, dc}]);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};