class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;

        for (int i = 0; i < numCourses; i++) {
            indegree[i] = 0;
            graph[i] = vector<int>();
        }

        for (auto& prereq : prerequisites) {
            int parent = prereq[0];
            int child = prereq[1];

            graph[parent].push_back(child);
            indegree[child]++;
        }

        queue<int> sources;
        for (auto& entry : indegree) {
            if (entry.second == 0) {
                sources.push(entry.first);
            }
        }

        vector<int> sortedOrder;
        while (!sources.empty()) {
            int x = sources.front();
            sources.pop();

            sortedOrder.push_back(x);

            vector<int> children = graph[x];
            for (int child : children) {
                indegree[child]--;

                if (indegree[child] == 0) {
                    sources.push(child);
                }
            }
        }
        return sortedOrder.size() == numCourses;
    }
};
