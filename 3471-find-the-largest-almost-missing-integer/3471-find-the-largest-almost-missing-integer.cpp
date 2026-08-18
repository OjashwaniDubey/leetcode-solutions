class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // windowCount[x] = number of size-k windows
        // in which x appears at least once
        vector<int> windowCount(51, 0);

        // Frequency inside current window
        vector<int> freq(51, 0);

        // First window
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }

        // Count each distinct number once for this window
        for (int x = 0; x <= 50; x++) {
            if (freq[x] > 0)
                windowCount[x]++;
        }

        // Slide the window
        for (int right = k; right < n; right++) {
            int left = right - k;

            freq[nums[left]]--;
            freq[nums[right]]++;

            // The window has changed, so count each number
            // that is present in this new window.
            for (int x = 0; x <= 50; x++) {
                if (freq[x] > 0)
                    windowCount[x]++;
            }
        }

        // Find largest number appearing in exactly one window
        for (int x = 50; x >= 0; x--) {
            if (windowCount[x] == 1)
                return x;
        }

        return -1;
    }
};