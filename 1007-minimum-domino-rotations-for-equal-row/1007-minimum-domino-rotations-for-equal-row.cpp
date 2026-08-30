class Solution {
public:
    int f(int x, vector<int>& tops, vector<int>& bottoms){
        int n = tops.size();
        int topRotations = 0;
        int bottomRotations = 0;
        for(int i = 0; i < n; i++){
            if(x != tops[i] && x != bottoms[i]) return -1;
            else if(tops[i] != x) topRotations++;
            else if(bottoms[i] != x) bottomRotations++;
        }
        return min(topRotations, bottomRotations);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int candidate1 = tops[0];
        int candidate2 = bottoms[0];
        int ans1 = f(candidate1, tops, bottoms);
        int ans2 = f(candidate2, tops, bottoms);
        if(ans1 == -1) return ans2;
        if(ans2 == -1) return ans1;
        return min(ans1, ans2);
    }
};