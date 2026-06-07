/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct state{
        int robHouse;
        int notRob;
    };
    state dfs(TreeNode* root){
        if(!root) return {0,0};
        state left = dfs(root->left);
        state right = dfs(root->right);
        state curr;
        curr.robHouse = root->val + left.notRob + right.notRob;
        curr.notRob = max(left.robHouse, left.notRob) + max(right.robHouse, right.notRob);
        return curr;
    }
    int rob(TreeNode* root) {
        state ans = dfs(root);
        return max(ans.robHouse, ans.notRob);
    }
};