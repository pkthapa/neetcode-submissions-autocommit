class Solution {
    bool dfs(vector<vector<char>>& board, string word, int row, int col, vector<vector<bool>>& vis, int idx) {
        if (word.size() == idx) {
            return true;
        }

        int ROWS = board.size();
        int COLS = board[0].size();

        // Check for boundary cases
        if (row < 0 || row >= ROWS ||
            col < 0 || col >= COLS ||
            vis[row][col] == true ||
            word[idx] != board[row][col]) {
            return false;
        }

        vis[row][col] = true;

        bool result = dfs(board, word, row - 1, col, vis, idx + 1) ||
                      dfs(board, word, row + 1, col, vis, idx + 1) ||
                      dfs(board, word, row, col - 1, vis, idx + 1) ||
                      dfs(board, word, row, col + 1, vis, idx + 1);

        vis[row][col] = false;

        return result;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));

        for(int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(board, word, r, c, vis, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
