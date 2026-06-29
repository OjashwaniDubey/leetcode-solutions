class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
            for(int j = 0; j < patterns.size(); j++){
                if(word.find(patterns[j]) != string::npos){
                    count++;
                }
            }
        return count;
    }
};