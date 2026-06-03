
   class Solution {
private:
    unordered_map<int, int> memo;
    
public:
    int f(int target, vector<int>& nums){
        if(target == 0) return 1;
        if(target < 0) return 0;
        
        if(memo.find(target) != memo.end()){
            return memo[target];
        }
        
        int ways = 0;
        for(int num : nums){
            ways += f(target - num, nums);
        }
        
        memo[target] = ways;
        return ways;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        return f(target, nums);
    }
};