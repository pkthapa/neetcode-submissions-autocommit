class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize all characters
        for (auto& word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];

            int len = min(w1.size(), w2.size());

            // Invalid case
            if (w1.size() > w2.size() && w1.substr(0, len) == w2.substr(0, len)) {
                return {};
            }

            for (int j = 0; j < len; j++) {
                if (w1[j]!= w2[j]) {
                    if (adj[w1[j]].count(w2[j]) == 0) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break; // only first difference matters
                }
            }
        }

        // Topological sort (BFS)
        queue<char> q;

        for (auto& [c, deg] : indegree) {
            if (deg == 0) {
                q.push(c);
            }
        }

        string result;
        while (!q.empty()) {
            char c = q.front();
            q.pop();

            result += c;

            for (char neighbor : adj[c]) {
                indegree[neighbor]--;
                if  (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Check cycle
        if (result.size() != indegree.size()) {
            return {};
        }
        return result;
    }
};
