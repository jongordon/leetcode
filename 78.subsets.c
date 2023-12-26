/*
 * @lc app=leetcode id=78 lang=c
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (76.55%)
 * Likes:    16285
 * Dislikes: 245
 * Total Accepted:    1.7M
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 *
 *
 */

// @lc code=start

#include <stdlib.h>

int countSetBits(int value, int numBits) {
    int res = 0;

    for (int i = 0; i < numBits; ++i) {
        if (value & (1 << i)) {
            ++res;
        }
    }

    return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int n = 1 << numsSize;
    int**res = calloc(n, sizeof(int*));

    *returnSize = n;
    *returnColumnSizes = malloc(n * sizeof(int));

    /* Empty subset first */
    res[0] = NULL;
    (*returnColumnSizes)[0] = 0;

    /* For the rest of the solutions, use the binary representation for each of n,
        returning values where a 1 is set in that representation to indicate the subset */
    for (int i = 1; i < n; ++i) {
        int count = countSetBits(i, numsSize);     /* Need to know how many in this subset we have upfront */
        int* current = calloc(count, sizeof(int));
        (*returnColumnSizes)[i] = count;

        /* For each bit set in this i (valid subset), we add the value from the input */
        for (int j = 0; j < numsSize; ++j) {
            if (i & (1 << j)) {
                current[--count] = nums[j];
            }
        }

        res[i] = current;
    }

    return res;
}
// @lc code=end

