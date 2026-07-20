class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = n * m - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int newRow = mid / n;
            int newCol = mid % n;
            int index = matrix[newRow][newCol];
            if(index == target) return true;
            else if(index > target) end = mid - 1;
            else start = mid + 1;
        }
        return false;
    }
};