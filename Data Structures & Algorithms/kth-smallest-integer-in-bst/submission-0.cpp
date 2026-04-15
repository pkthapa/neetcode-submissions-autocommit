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
    int kthSmallest(TreeNode* root, int& k) {
        if (root == nullptr) {
            return {};
        }
        // 1. Search left subtree
        int val = kthSmallest(root->left, k);

        // 2. If answer was found in left subtree, propagate it up immediately
        if (k == 0) {
            return val;
        }

        // 3. Visit current node
        if (--k == 0) {
            return root->val;
        }

        // 4. Search right subtree
        return kthSmallest(root->right, k);
    }
};
