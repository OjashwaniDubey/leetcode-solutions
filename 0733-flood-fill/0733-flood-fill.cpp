class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int color){
        ans[sr][sc] = color;
        int ini = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        for(int delrow = -1; delrow <= 1; delrow++){
            for(int delcol = -1; delcol <= 1; delcol++){
                if(abs(delrow) + abs(delcol) != 1) continue;
                int row = sr + delrow;
                int col = sc + delcol;
                if(row >= 0 && row < n && col >= 0 && col < m && ans[row][col] == ini && ans[row][col] != color){
                    dfs(row, col, ans, image, color);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, color);
        return ans;
    }
};