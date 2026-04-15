class Solution {
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int dx[] {-1, 0, 1, 0};
        int dy[] {0, 1, 0, -1};

        grid[r][c] = '0'; // Reset to water so that this cell is not visited again

        for (int i = 0; i < 4; i++) {
            int newCell_r = r + dx[i];
            int newCell_c = c + dy[i];

            if ((0 <= newCell_r && newCell_r < grid.size()) &&
                (0 <= newCell_c && newCell_c < grid[0].size()) &&
                (grid[newCell_r][newCell_c] == '1')) {
                dfs(grid, newCell_r, newCell_c);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    result++;
                    dfs(grid, r, c);
                }
            }
        }
        return result;
    }
};
