class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool hasFirstRowZero = false;
        bool hasFirstColZero = false;

        int r = matrix.size();
        int c = matrix[0].size();

        for (int i = 0; i < c; i++) {
            if (matrix[0][i] == 0) {
                hasFirstRowZero = true;
                break;
            }
        }

        for (int i = 0; i < r; i++) {
            if (matrix[i][0] == 0) {
                hasFirstColZero = true;
            }
        }

        // Mark first row and first col as 0 based on inner matrix
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Based on firstrow and firstcol, update inner matrix
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Update first row
        if (hasFirstRowZero) {
            for (int i = 0; i < c; i++) {
                matrix[0][i] = 0;
            }
        }

        // Update first col
        if (hasFirstColZero) {
            for (int i = 0; i < r; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
