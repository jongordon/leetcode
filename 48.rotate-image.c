/*
 * @lc app=leetcode id=48 lang=c
 *
 * [48] Rotate Image
 */

// @lc code=start
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    /* Rotating a matrix can be done in two steps - transpose and reflect */

    /* Transpose along the diagonal first */
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = i + 1; j < matrixSize; ++j) {
            int tmp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = tmp;
        }
    }

    /* Now reflect left to right */
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize / 2; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - 1 - j];
            matrix[i][matrixSize - 1 - j] = tmp;
        }
    }
}
// @lc code=end

