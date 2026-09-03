class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
    int minOdd = INT_MAX;
    int minEven = INT_MAX;

    for (int x : nums1) {
        if (x % 2)
            minOdd = min(minOdd, x);
        else
            minEven = min(minEven, x);
    }

    // Already uniform
    if (minOdd == INT_MAX || minEven == INT_MAX)
        return true;

    // Make every even number odd using the smallest odd number.
    return minOdd < minEven;
}
};