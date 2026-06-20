class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<vector<int>>r;
        r.push_back({1, 0});
        for(auto &x : restrictions){
            r.push_back({x[0], x[1]});
        }
        bool found = false;
        for(auto &x : restrictions){
            if(x[0] == n){
                found = true;
                break;
            }
        }
        if(!found){
            r.push_back({n, n-1});
        }
        sort(r.begin(), r.end());
        for(int i = 1; i < r.size(); i++){
            int dist = r[i][0] - r[i-1][0];
            r[i][1] = min(r[i][1], r[i-1][1] + dist);
        }
        for(int i = r.size()-2; i >= 0; i--){
            int dist = r[i+1][0] - r[i][0];
            r[i][1] = min(r[i][1], r[i+1][1] + dist);
        }
        int ans = 0;
        for(int i = 1; i < r.size(); i++){
            int d = r[i][0] - r[i-1][0];
            int h1 = r[i-1][1];
            int h2 = r[i][1];
            ans = max(ans, (d+h1+h2)/2);
        }
        return ans;
    }
};