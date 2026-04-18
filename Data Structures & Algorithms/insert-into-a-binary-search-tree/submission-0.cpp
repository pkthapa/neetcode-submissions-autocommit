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
    void insert(TreeNode** node, int val) {
        if (*node == nullptr) {
            *node = new TreeNode(val);
            return;
        }

        if ((*node)->val >= val) {
            insert(&(*node)->left, val);
        }
        else {
            insert(&(*node)->right, val);
        }
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(&root, val);
        return root;
    }
};