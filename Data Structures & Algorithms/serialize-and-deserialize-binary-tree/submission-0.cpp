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

class Codec {
    TreeNode* deserializeHelper(const string& data, int& index) {
        // Parse one comma-delimited token starting at `index`
        int commaPos = data.find(',', index);
        string token = data.substr(index, commaPos - index);
        index = commaPos + 1;       // advance past the comma

        if (token == "N") {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(token));
        node->left  = deserializeHelper(data, index);
        node->right = deserializeHelper(data, index);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "N,";
        }
        return to_string(root->val) + "," +
            serialize(root->left) +
            serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;              // tracks position across recursive calls
        return deserializeHelper(data, index);
    }
};
