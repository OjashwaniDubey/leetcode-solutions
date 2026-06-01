class Solution {
public:
    int maxRectangle(vector<int> &heights, int n){
        stack<int> st;
        vector<int> right(n, 0);
        vector<int> left(n, 0);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            int length = heights[i];
            int currArea = length * width;
            ans = max(ans, currArea);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()){
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        for(int j = 0; j < n; j++){
            heights[j] = matrix[0][j] - '0';
        }
        int area = maxRectangle(heights, n);
            for(int i = 1; i < m; i++){
                for(int j = 0; j < n; j++){
                   if(matrix[i][j] == '1'){
                     heights[j] += 1;
                   }
                   else{
                    heights[j] = 0;
                   }
                }
            int newArea = maxRectangle(heights , n);
            area = max(area, newArea);
            }
      return area;
    }
};