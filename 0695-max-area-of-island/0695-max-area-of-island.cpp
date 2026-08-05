class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0 || vis[r][c]) return 0;
        int ans = 1;
        vis[r][c] = 1;
        ans += dfs(r-1, c, grid, vis);
        ans += dfs(r, c+1, grid, vis);
        ans += dfs(r+1, c, grid, vis);
        ans += dfs(r, c-1, grid, vis);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int maxArea = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    maxArea = max(maxArea, dfs(i, j, grid, vis));
                }
            }
        }
        return maxArea;
    }
};