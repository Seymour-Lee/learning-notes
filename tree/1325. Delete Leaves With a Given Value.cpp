/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == nullptr) return nullptr;
        root->left = removeLeafNodes(root->left, target); 
        root->right = removeLeafNodes(root->right, target); 
        if (root->val == target && root->left == nullptr && root->right == nullptr) { 
            return nullptr; 
        } 
        return root; 
    }
};