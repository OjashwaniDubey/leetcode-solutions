class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n = stones.size();
        for(int i = 0; i < n; i++){
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            if(s1 != s2){
                pq.push(s1-s2);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};