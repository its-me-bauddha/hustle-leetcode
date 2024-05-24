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
    

    bool hasPathSum(TreeNode* root, int tSum) {
        if(!root) return false;
        tSum -= root ->val;

        if(tSum ==0 && !root ->left && !root ->right) 
            return true;

        return hasPathSum(root->left,tSum) || hasPathSum(root->right,tSum);
    }
};