class PrefixTree {
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;

        for (auto c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new Node();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;

        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;

        for (auto c : prefix) {
            if (node->children[c - 'a'] == nullptr) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return true;
    }
};
