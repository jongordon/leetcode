/*
 * @lc app=leetcode id=371 lang=c
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Medium (51.28%)
 * Likes:    3957
 * Dislikes: 5334
 * Total Accepted:    437.5K
 * Total Submissions: 852.8K
 * Testcase Example:  '1\n2'
 *
 * Given two integers a and b, return the sum of the two integers without using
 * the operators + and -.
 *
 *
 * Example 1:
 * Input: a = 1, b = 2
 * Output: 3
 * Example 2:
 * Input: a = 2, b = 3
 * Output: 5
 *
 *
 * Constraints:
 *
 *
 * -1000 <= a, b <= 1000
 *
 *
 */

// @lc code=start

#include <stdint.h>

int getSum(int a, int b) {
    /* Summing involves two parts - the carry and the non-carry per binary digit.
        Carrying is necessary when both digits are 1, so we can use an AND to determine that and shift it left.
        The non-carry is a simply XOR of the two digits. (00 = 0, 01 = 1, 10 = 1, 11 dealt with above == XOR)
        This can be repeated for all digits until there is no more carry. */
    while (a != 0) {
        /* Use unsigned casts to prevent carrying a negative number indefinitely */
        uint32_t c = ((uint32_t)a & (uint32_t)b) << 1;
        uint32_t d = a ^ b;
        a = c;
        b = d;
    }

    return b;
}
// @lc code=end

