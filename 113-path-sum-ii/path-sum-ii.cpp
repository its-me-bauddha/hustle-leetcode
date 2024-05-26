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
    void  hasPathSum(TreeNode* root, int tSum,vector<vector<int>> &ans,vector<int>&temp) {
        if(!root)   return ;
        temp.push_back(root->val);
        if(tSum ==root->val && !root ->left && !root ->right){ 
            ans.push_back(temp);
        }
        hasPathSum(root->left,tSum - root ->val,ans,temp);
        hasPathSum(root->right,tSum - root ->val,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<vector<int>> ans;
         vector<int> temp;
         hasPathSum(root,targetSum,ans,temp);
         return ans;
    }
};