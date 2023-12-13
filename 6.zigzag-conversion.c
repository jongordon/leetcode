/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] Zigzag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (46.50%)
 * Likes:    7026
 * Dislikes: 13777
 * Total Accepted:    1.2M
 * Total Submissions: 2.5M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 *
 * Example 3:
 *
 *
 * Input: s = "A", numRows = 1
 * Output: "A"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000
 *
 *
 */

// @lc code=start

#include <stdlib.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || numRows >= len) {
        return s;
    }

    /* Calculate the number of columns we will need */
    int colsPerRep = numRows - 1;
    int countPerRep = numRows + (numRows - 2);
    int reps = len / countPerRep;
    int rem = 0;
    if (reps > 0) {
        rem = len % (reps * countPerRep);
    } else {
        rem = len;
    }
    int remCols = 0;
    if (rem > 0) {
        remCols = rem - numRows <= 0 ? 1 : (rem - numRows) + 1;
    }
    int numCols = remCols + (colsPerRep * reps);

    /* Allocate the full grid */
    char** grid = malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; ++i) {
        /* Calloc the columns so that we can detect gaps later */
        grid[i] = calloc(numCols, sizeof(char));
    }

    /* Now step through the input string, filling columns, then diagonal, until input is empty */
    int pos = 0, col = 0, row = 0;
    while (s[pos]) {
        if ((pos % (numRows - 1)) == 0) {
            /* We are on a full column */
            for (int i = 0; i < numRows && s[pos]; ++i) {
                grid[i][col] = s[pos++];
            }
            row = numRows - 1;  /* done with the full column, prepare for diagonal */
        } else {
            /* On a diagonal, move up and to the right each time */
            --row;
            grid[row][col] = s[pos++];
        }
        /* Whether we did a full column or one as part of a diagonal, move to the next one */
        ++col;
    }

    /* Now iterate over grid to fill the output string, skipping any gaps */
    char* res = calloc(len + 1, sizeof(char));
    pos = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (grid[i][j] != '\0') {
                res[pos++] = grid[i][j];
            }
        }
    }

    /* Finished with grid now */
    for (int i = 0; i < numRows; ++i) {
        /* Calloc the columns so that we can detect gaps later */
        free(grid[i]);
    }
    free(grid);

    return res;
}
// @lc code=end

