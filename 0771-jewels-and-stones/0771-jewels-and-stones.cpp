class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for(char s : stones){
            for(char j : jewels){
                if(s == j){
                    ans += 1;
                }
            }
        }
        return ans;
    }
};