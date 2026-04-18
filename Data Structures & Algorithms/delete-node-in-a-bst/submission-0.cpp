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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return {};
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // If only one right child
            if (root->left == nullptr) {
                return root->right;
            }
            // If only one left child
            if (root->right == nullptr) {
                return root->left;
            }

            // If the node has 2 children, then replace
            // root (current node) with the successor (smallest
            // from the right sub-tree)

            // Get the successor
            TreeNode* successor = findMin(root->right);
            
            // Now replace the current node with successor
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) {
        // Keep checking for left subtree only to find the smallest element
        while (node->left != nullptr) {
            // The left subtree of the parent's right-part (subtree)
            // will have the smallest element
            node = node->left;
        }
        return node;
    }
};