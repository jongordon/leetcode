/*
 * @lc app=leetcode id=200 lang=c
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (58.13%)
 * Likes:    21623
 * Dislikes: 471
 * Total Accepted:    2.4M
 * Total Submissions: 4.1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 *
 *
 */

// @lc code=start

void search(char* *grid, int r, int c, int rows, int cols) {
    /* Is this a valid cell? */
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') {
        /* Invalid location or is water */
        return;
    }

    /* Clear this cell */
    grid[r][c] = '0';

    /* Check all four directions recursively */
    search(grid, r, c + 1, rows, cols);
    search(grid, r + 1, c, rows, cols);
    search(grid, r, c - 1, rows, cols);
    search(grid, r - 1, c, rows, cols);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int num_islands = 0;

    /* Start off by looking at every cell for a '1' */
    for (int r = 0; r < gridSize; ++r) {
        for (int c = 0; c < gridColSize[0]; ++c) {
            if (grid[r][c] == '1') {
                ++num_islands;

                /* Searching for connected '1's, replacing with '0', so we don't count them here */
                search(grid, r, c, gridSize, gridColSize[0]);
            }
        }
    }

    return num_islands;
}
// @lc code=end

