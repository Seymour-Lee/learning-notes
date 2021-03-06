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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> order2vals;
        vector<vector<int>> ans;
        queue<pair<int, TreeNode *>> q;
        q.push({0, root});
        while(q.empty() == false){
            auto p = q.front(); q.pop();
            if(p.second != nullptr){
                order2vals[p.first].push_back(p.second->val);
                q.push({p.first-1, p.second->left});
                q.push({p.first+1, p.second->right});
            }
        }
        for(auto it: order2vals) ans.push_back(it.second);
        return ans;
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        map<int, vector<int>> p2v;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto p = q.front(); q.pop();
                auto node = p.first;
                auto pos = p.second;
                p2v[pos].push_back(node->val);
                if(node->left) q.push({node->left, pos-1});
                if(node->right) q.push({node->right, pos+1});
            }
        }
        for(auto p: p2v) ans.push_back(p.second);
        return ans;
    }
};