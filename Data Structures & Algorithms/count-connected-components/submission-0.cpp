class Solution {
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;

        for (auto neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // unordered_map<int, vector<int>> graph;
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int result = 0;
        
        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                result++;
            }
        }
        return result;
    }
};
