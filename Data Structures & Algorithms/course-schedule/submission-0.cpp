class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;

        for (int i = 0; i < numCourses; i++) {
            indegree[i] = 0;
            graph[i] = vector<int>();
        }

        for (auto prereq : prerequisites) {
            int parent = prereq[0];
            int child = prereq[1];

            graph[parent].push_back(child);
            indegree[child]++;
        }

        // Find all sources with 0 indegree
        queue<int> sources;
        for (auto entry : indegree) {
            if (entry.second == 0) {
                sources.push(entry.first);
            }
        }

        vector<int> sortedorder;
        while (!sources.empty()) {
            auto x = sources.front();
            sources.pop();

            sortedorder.push_back(x);

            for (auto child : graph[x]) {
                indegree[child]--;

                if (indegree[child] == 0) {
                    sources.push(child);
                }
            }
        }

        return sortedorder.size() == numCourses;
    }
};
