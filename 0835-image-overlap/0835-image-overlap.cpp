class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for(int dr = -(n-1); dr <= n-1; dr++){
            for(int dc = -(n-1); dc <= n-1; dc++){
                int overlap = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(img1[i][j] == 1){
                            int newi = i + dr;
                            int newj = j + dc;
                            if(newi >= 0 && newi < n && newj >= 0 && newj < n){
                                if(img2[newi][newj] == 1) overlap++;
                            }
                        }
                    }
                }
                ans = max(ans, overlap);
            }
        }
        return ans;
    }
};