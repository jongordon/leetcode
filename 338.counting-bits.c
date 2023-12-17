/*
 * @lc app=leetcode id=338 lang=c
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Easy (77.75%)
 * Likes:    10707
 * Dislikes: 491
 * Total Accepted:    997K
 * Total Submissions: 1.3M
 * Testcase Example:  '2'
 *
 * Given an integer n, return an array ans of length n + 1 such that for each i
 * (0 <= i <= n), ans[i] is the number of 1's in the binary representation of
 * i.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: [0,1,1]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5
 * Output: [0,1,1,2,1,2]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 10^5
 *
 *
 *
 * Follow up:
 *
 *
 * It is very easy to come up with a solution with a runtime of O(n log n). Can
 * you do it in linear time O(n) and possibly in a single pass?
 * Can you do it without using any built-in function (i.e., like
 * __builtin_popcount in C++)?
 *
 *
 */

// @lc code=start

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    /* Counting from zero, int array size will be one more than n */
    int* ans = calloc((n + 1), sizeof(int));

    /* Scan all integers from 1 to n (0 is 0 and the array was calloc'd), and count 1s in each int */
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i >> 1] + (i & 0x1);   /* We extend previous counts already calculated */
    }

    *returnSize = n + 1;
    return ans;
}
// @lc code=end

