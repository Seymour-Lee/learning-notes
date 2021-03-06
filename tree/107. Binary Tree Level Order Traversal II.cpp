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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<TreeNode *> q;
        stack<vector<int>> stk;
        q.push(root);
        int size = 1;
        vector<int> level;
        while(!q.empty()){
            size = q.size();
            while(size--){
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            stk.push(level);
            level.clear();
        }
        while(!stk.empty()){
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty() == false){
            int size = q.size();
            vector<int> cur = {};
            while(size--){
                auto node = q.front();
                q.pop();
                cur.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(cur);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};