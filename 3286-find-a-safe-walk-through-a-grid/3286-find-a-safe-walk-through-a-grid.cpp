class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        deque<pair<int, int>> dq;
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];
        dq.push_front({0,0});
        vector<pair<int, int>> dir = {
            {1,0},{0,1},{-1,0},{0,-1}
        };
        while(!dq.empty()){
            auto [x, y] = dq.front();
            dq.pop_front();
            for(auto[dx, dy] : dir){
                int nx = x + dx;
                int ny = y + dy;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                    continue;
                }
                int weight = grid[nx][ny];
                int newdist = dist[x][y] + weight;
                if(newdist < dist[nx][ny]){
                    dist[nx][ny] = newdist;
                    if(weight == 0){
                    dq.push_front({nx, ny});
                    }
                    else{
                    dq.push_back({nx, ny});
                    }
                }
            }
        }
        return dist[n-1][m-1] < health;
    }
};