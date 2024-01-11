/*
 * @lc app=leetcode id=240 lang=c
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (51.96%)
 * Likes:    11534
 * Dislikes: 192
 * Total Accepted:    877.7K
 * Total Submissions: 1.7M
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * Write an efficient algorithm that searches for a value target in an m x n
 * integer matrix matrix. This matrix has the following properties:
 *
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 5
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 20
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * All the integers in each row are sorted in ascending order.
 * All the integers in each column are sorted in ascending order.
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start

#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int rows = matrixSize;
    int cols = matrixColSize[0];

    /* Start at top-right, divide and conquer */
    int i = 0, j = cols - 1;

    /* don't exceed limits of grid */
    while (i < rows && j >= 0) {
        int curr = matrix[i][j];    /* Current cell */
        if (curr == target) {
            /* Target found */
            return true;
        }

        if (curr > target) {
            /* We can come back a column as we're sorted ASC and too high */
            --j;
        }
        else {
            /* We can move up a row as we're sorted ASC and too low */
            ++i;
        }
    }

    return false;
}
// @lc code=end

