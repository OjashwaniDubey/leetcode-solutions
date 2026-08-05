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
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto edges : invocations){
            int u = edges[0];
            int v = edges[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n, 0);
        dfs(k, adj, vis);
        for(auto edge : invocations){
            int u = edge[0];
            int v = edge[1];
            if(vis[u] == 0 && vis[v] == 1){
                vector<int> ans;
                for(int i = 0; i < n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};