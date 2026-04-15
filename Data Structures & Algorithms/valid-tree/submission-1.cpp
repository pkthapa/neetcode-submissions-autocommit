class Solution {
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& graph) {
        vis[node] = true;

        for (auto& neighbor : graph[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, vis, graph);
            }
        }
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        dfs(0, vis, graph);

        // Check if all nodes are visited
        for (bool v : vis) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
};
