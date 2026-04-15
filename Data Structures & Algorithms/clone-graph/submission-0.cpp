/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return {};
        }
        unordered_map<Node*, Node*> mp;
        
        Node* clone = new Node(node->val);
        mp[node] = clone;

        queue<Node*> q({node});

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (auto& neighbor : curr->neighbors) {
                // If not cloned
                if (mp.find(neighbor) == mp.end()) {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                // Link neighbor to cloned node
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }
        return clone;
    }
};
