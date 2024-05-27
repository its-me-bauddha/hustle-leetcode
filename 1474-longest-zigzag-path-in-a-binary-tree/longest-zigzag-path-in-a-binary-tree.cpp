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
   
    int solve(TreeNode* root , int left,int right ,int &maxPath){
        if(!root) return 0;
         maxPath =  max(maxPath,max(left,right)); // store the longest path 
        
        solve(root->left,right+1,0,maxPath); //. goto to left via making right val =0 ,left = right+1
        solve(root->right,0,left+1,maxPath);

        return maxPath;
    }
    int longestZigZag(TreeNode* root) {

       int maxPath = 0;
       int ans= solve(root,0,0,maxPath);
       return ans;
    }
};