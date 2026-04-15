class Solution {
    // int dx[] = {1, 0, -1, 0};
    // int dy[] = {0, -1, 0, 1};
    int row, col;
    vector<vector<int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& vis) {
        vis[r][c] = true;

        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            // Boundary check
            if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                continue;
            }

            if (vis[nr][nc]) {
                continue;
            }

            // Reverse flow condition
            if (heights[nr][nc] < heights[r][c]) {
                continue;
            }

            dfs(heights, nr, nc, vis);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();

        vector<vector<bool>> visPacific(row, vector<bool>(col, false));
        vector<vector<bool>> visAtlantic(row, vector<bool>(col, false));

        // Pacific DFS (top row)
        for (int i = 0; i < col; i++) {
            dfs(heights, 0, i, visPacific);
        }

        // Pacific DFS (left col)
        for (int i = 0; i < row; i++) {
            dfs(heights, i, 0, visPacific);
        }

        // Atlantic DFS (bottom row)
        for (int i = 0; i < col; i++) {
            dfs(heights, row - 1, i, visAtlantic);
        }

        // Atlantic DFS (right col)
        for (int i = 0; i < row; i++) {
            dfs(heights, i, col - 1, visAtlantic);
        }

        // Collect result
        vector<vector<int>> result;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (visPacific[i][j] && visAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
