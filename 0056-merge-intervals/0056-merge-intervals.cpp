class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> temp;
        int start = intervals[0][0];
        int End = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= End){
                End = max(End, intervals[i][1]);
            }
            else{
                temp.push_back({start, End});
                start = intervals[i][0];
                End = intervals[i][1];
            }
        }
        temp.push_back({start, End});
        return temp;
    }
};