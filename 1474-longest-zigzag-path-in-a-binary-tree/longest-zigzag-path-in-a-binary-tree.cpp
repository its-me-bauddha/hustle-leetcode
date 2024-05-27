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
   
    int solve(TreeNode* root , int steps,bool goLeft ,int &maxPath){
        if(!root) return 0;
         maxPath =  max(maxPath,steps); // store the longest path 
        
        if(goLeft){ // go to left
            solve(root->left,steps+1,false,maxPath);  // go to right
            solve(root->right,1,true,maxPath); // go to left -> restart the new path
        }
        else{
            // right jana hai 
            solve(root->right,steps+1,true,maxPath); // go to right
            solve(root->left,1,false,maxPath); // restart the new path 
        }
        return maxPath;
    }
    int longestZigZag(TreeNode* root) {
        int steps = 0;
        bool goLeft = true;
        int maxPath = 0;
       int ans= solve(root,steps,goLeft ,maxPath);
        return ans;
    }
};