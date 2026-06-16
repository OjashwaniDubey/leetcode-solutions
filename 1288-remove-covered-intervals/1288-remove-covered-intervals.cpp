class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 0;
        int end = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][1] > end){
                cnt++;
                end = intervals[i][1];
            }
        }
        return cnt;
    }
};