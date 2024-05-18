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
    int  solveDcoins(TreeNode*root,int &moves){
        if(!root) return 0;

        int left =  solveDcoins(root ->left,moves);
        int right =  solveDcoins(root ->right,moves);

        moves += abs(left) + abs(right);
        return (left + right + root ->val) -1;

    }
    int distributeCoins(TreeNode* root) {
        int moves  = 0;
        solveDcoins(root,moves);

       return moves;        
    } 
};