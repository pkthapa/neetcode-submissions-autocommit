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
    bool helper(TreeNode* node, int64_t minVal, int64_t maxVal) {
        if (node == nullptr) {
            return true;
        }
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        return helper(node->left, minVal, node->val) &&
            helper(node->right, node->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return helper(root, INT64_MIN, INT64_MAX);
    }
};
