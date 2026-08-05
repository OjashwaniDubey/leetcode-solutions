class Solution {
public:
    void dfs(int u, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[u] = 1;
        for(int v = 0; v < isConnected.size(); v++){
            if(!vis[v] && isConnected[u][v] == 1){
                dfs(v, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, isConnected, vis);
                provinces++;
            }
        }
        return provinces;
    }
};