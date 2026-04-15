class Solution {
    void dfs(vector<vector<int>>& grid, int r, int c, int& tempArea) {
        grid[r][c] = 0;
        tempArea++;

        int dx[] {-1, 0, 1, 0};
        int dy[] {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newCell_r = r + dx[i];
            int newCell_c = c + dy[i];

            if ((0 <= newCell_r && newCell_r < grid.size()) &&
                (0 <= newCell_c && newCell_c < grid[0].size()) &&
                (grid[newCell_r][newCell_c] == 1)) {
                dfs(grid, newCell_r, newCell_c, tempArea);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int tempArea = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    dfs(grid, r, c, tempArea);
                    maxArea = max(maxArea, tempArea);
                    tempArea = 0;
                }
            }
        }
        return maxArea;
    }
};
