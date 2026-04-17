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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> result;
        queue<TreeNode*> q ({root});

        while (!q.empty()) {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }

                if (i == 0) {
                    result.push_back(curr->val);
                }
            }
        }
        return result;
    }
};
