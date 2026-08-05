class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& vis){
        vis[u] = 1;
        for(int v : adj[u]){
            if(!vis[v]){
                dfs(v, adj, vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(source, adj, vis);
        for(int i = 0; i < n; i++){
            if(vis[i] == 0 && i == destination) return false;
        }
        return true;
    }
};