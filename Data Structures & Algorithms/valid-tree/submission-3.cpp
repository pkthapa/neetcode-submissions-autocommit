class Solution {
    // Path compression + find
    int find(int x, vector<int>& parent) {
        if (x != parent[x]) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    void unite(int u, int v, vector<int>& parent) {
        int pu = find(u, parent);
        int pv = find(v, parent);

        if (pu != pv) {
            parent[pu] = pv; // Attach one root to another
        }
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<int> parent(n);

        // Initialize parent to itself
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int pu = find(u, parent);
            int pv = find(v, parent);

            // If both have same parent, then it is a cycle
            if (pu == pv) {
                return false;
            }

            unite(u, v, parent);
        }
        return true;
    }
};
