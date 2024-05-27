/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {      
        if(!root) return NULL;
        int result = 0  , level = 0, totalSum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int qSize = q.size(), levelSum = 0;
            while (qSize--) {
                TreeNode* temp = q.front();
                q.pop();

                levelSum += temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            level++;
            if(levelSum > totalSum ) 
                result = level;
            totalSum = max(levelSum , totalSum);
        }
        return result;
    }
};