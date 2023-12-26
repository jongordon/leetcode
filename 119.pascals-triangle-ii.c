/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (63.39%)
 * Likes:    4687
 * Dislikes: 327
 * Total Accepted:    829K
 * Total Submissions: 1.3M
 * Testcase Example:  '3'
 *
 * Given an integer rowIndex, return the rowIndex^th (0-indexed) row of the
 * Pascal's triangle.
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 *
 *
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= rowIndex <= 33
 *
 *
 *
 * Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
 * space?
 *
 */

// @lc code=start

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int n = rowIndex + 1;
    int* res = malloc(n * sizeof(int));
    *returnSize = n;

    /* First element is always 1 */
    res[0] = 1;

    for (int i = 1; i < n; ++i) {
        res[i] = 1;
        int prev = 1;

        /* Each time we iterate over i, we add what we would have expected on i - 1
            effectively building the triangle in place */
        for (int j = 1; j < i; ++j) {
            res[j] += prev;
            prev = res[j] - prev;   /* New previous value for next i */
        }
    }

    return res;
}
// @lc code=end

