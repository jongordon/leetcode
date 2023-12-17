/*
 * @lc app=leetcode id=201 lang=c
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (42.85%)
 * Likes:    3160
 * Dislikes: 220
 * Total Accepted:    263.5K
 * Total Submissions: 614.8K
 * Testcase Example:  '5\n7'
 *
 * Given two integers left and right that represent the range [left, right],
 * return the bitwise AND of all numbers in this range, inclusive.
 *
 *
 * Example 1:
 *
 *
 * Input: left = 5, right = 7
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: left = 0, right = 0
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: left = 1, right = 2147483647
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= left <= right <= 2^31 - 1
 *
 *
 */

// @lc code=start

#include <stdint.h>

int rangeBitwiseAnd(int left, int right) {
    uint32_t shift = 0;

    /* Loop until the numbers are the same. They will either be 00 or 11.
       If 00, the answer is 0. If 11, the answer is left << by number of times looped.
    */
    while (left != right) {
        left >>= 1;
        right >>= 1;
        ++shift;
    }

    return (left << shift);
}
// @lc code=end

