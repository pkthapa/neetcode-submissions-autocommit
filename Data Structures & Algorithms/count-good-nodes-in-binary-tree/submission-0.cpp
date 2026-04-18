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
    int dfs(TreeNode* node, int maxSoFar) {
        if (node == nullptr) {
            return 0;
        }
        int count = 0;

        // Check if the current node is good
        if (node->val >= maxSoFar) {
            count = 1;

            // Update max for children
            maxSoFar = node->val;
        }

        // Recurse
        count += dfs(node->left, maxSoFar);
        count += dfs(node->right, maxSoFar);

        return count;
    }

public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return dfs(root, root->val);
    }
};
