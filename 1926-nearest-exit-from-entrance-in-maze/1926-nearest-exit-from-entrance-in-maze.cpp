class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int dist = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()){
            int sz = q.size();
            dist++;
            while(sz--){
                auto [r, c] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int newr = r + dr[i];
                    int newc = c + dc[i];
                    if(newr < 0 || newr >= m || newc < 0 || newc >= n) continue;
                    if(maze[newr][newc] == '+') continue;
                    maze[newr][newc] = '+';
                    if(newr == 0 || newr == m-1 || newc == 0 || newc == n-1) return dist;
                    q.push({newr, newc});
                }
            }
        }
        return -1;
    }
};