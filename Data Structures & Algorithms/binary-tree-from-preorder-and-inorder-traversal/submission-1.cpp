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
    // HashMap to store value -> index in inorder array
    // This gives O(1) lookup instead of O(n) linear search
    unordered_map<int, int> inorderIdx;

public:
    // preorder = [3, 9, 20, 15, 7]
    // inorder  = [9, 3, 15, 20, 7]
    TreeNode* build(vector<int>& preorder,
                    int preStart, int preEnd, // current window in preorder
                    int inStart, int inEnd) { // current window in inorder
        // Base case: no elements left to process in this subtree
        if (preStart > preEnd || inStart > inEnd) {
            return {};
        }

        // ── Step 1: Identify the root ──────────────────────────────────────
        // In preorder, the first element of the current window is always
        // the root of this subtree
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // ── Step 2: Locate root in inorder ────────────────────────────────
        // Everything to the LEFT  of this index → left subtree
        // Everything to the RIGHT of this index → right subtree
        int mid = inorderIdx[rootVal];

        // ── Step 3: Count left subtree size ───────────────────────────────
        // We need this to correctly slice the preorder array
        // (preorder visits all left nodes before any right node)
        int leftSize = mid - inStart;

        // ── Step 4: Recurse for left subtree ──────────────────────────────
        // preorder window: skip the root (preStart+1), take leftSize elements
        // inorder  window: everything left of mid (inStart to mid-1)
        root->left = build(preorder,
                           preStart + 1, preStart + leftSize,
                           inStart, mid - 1);

        // ── Step 5: Recurse for right subtree ─────────────────────────────
        // preorder window: everything after the left subtree block
        // inorder  window: everything right of mid (mid+1 to inEnd)
        root->right = build(preorder,
                            preStart + leftSize + 1, preEnd,
                            mid + 1, inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Pre-populate the map: for each value, store its index in inorder
        for (int i = 0; i < inorder.size(); i++) {
            inorderIdx[inorder[i]] = i;
        }

        // Kick off recursion with full range of both arrays
        return build(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
