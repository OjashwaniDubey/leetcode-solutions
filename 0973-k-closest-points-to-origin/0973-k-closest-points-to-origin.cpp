class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>>pq;
        int dis = 0;
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0]*points[i][0];
            int y = points[i][1]*points[i][1];
            dis = x + y;
            pq.push({dis, i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto [dis, idx] = pq.top();
            pq.pop();
            ans.push_back(points[idx]);
        }
        return ans;
    }
};