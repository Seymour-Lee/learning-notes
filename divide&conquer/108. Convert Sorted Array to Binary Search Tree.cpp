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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return binary(nums, 0, nums.size()-1);
    }
    
private:
    TreeNode * binary(vector<int>& nums, int l, int r){
        if(l > r) return nullptr;
        if(l == r) return new TreeNode(nums[l]);
        int m = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = binary(nums, l, m-1);
        root->right = binary(nums, m+1, r);
        return root;
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        int pos = nums.size() / 2;
        TreeNode *node = new TreeNode(nums[pos]);
        auto l = vector<int>(nums.begin(), nums.begin()+pos);
        auto r = vector<int>(next(nums.begin()+pos), nums.end());
        node->left = sortedArrayToBST(l);
        node->right = sortedArrayToBST(r);
        return node;
    }
};