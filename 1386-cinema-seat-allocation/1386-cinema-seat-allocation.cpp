class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> mp;

        // Store reserved seats of each row as a bitmask
        for(auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            if(s >= 2 && s <= 9) {
                mp[row] |= (1 << (s - 2));
            }
        }

        // Every completely empty row can accommodate 2 groups
        long long ans = 2LL * n;

        int leftMask = 15;     // seats 2,3,4,5
        int middleMask = 60;   // seats 4,5,6,7
        int rightMask = 240;   // seats 6,7,8,9

        // Only rows having reservations can be problematic
        for(auto &[row, mask] : mp) {

            // This row was initially counted as 2
            ans -= 2;

            // Can put groups on both sides
            if((mask & leftMask) == 0 &&
               (mask & rightMask) == 0) {
                ans += 2;
            }

            // Otherwise, can put at least one group
            else if((mask & leftMask) == 0 ||
                    (mask & middleMask) == 0 ||
                    (mask & rightMask) == 0) {
                ans += 1;
            }
        }

        return ans;
    }
};