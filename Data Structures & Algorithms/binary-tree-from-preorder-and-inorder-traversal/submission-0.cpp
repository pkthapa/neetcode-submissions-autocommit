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
    unordered_map<int, int> inorderIdx;

public:
    // preorder = [3, 9, 20, 15, 7]
    // inorder  = [9, 3, 15, 20, 7]
    TreeNode* build(vector<int>& preorder,
                    int preStart, int preEnd,
                    int inStart, int inEnd) {
        // Base case
        if (preStart > preEnd || inStart > inEnd) {
            return {};
        }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIdx[rootVal];
        int leftSize = mid - inStart;

        root->left = build(preorder,
                           preStart + 1, preStart + leftSize,
                           inStart, mid - 1);

        root->right = build(preorder,
                            preStart + leftSize + 1, preEnd,
                            mid + 1, inEnd);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderIdx[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
