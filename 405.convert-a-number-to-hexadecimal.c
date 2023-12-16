/*
 * @lc app=leetcode id=405 lang=c
 *
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (47.72%)
 * Likes:    1276
 * Dislikes: 207
 * Total Accepted:    134.7K
 * Total Submissions: 282.2K
 * Testcase Example:  '26'
 *
 * Given an integer num, return a string representing its hexadecimal
 * representation. For negative integers, two’s complement method is used.
 *
 * All the letters in the answer string should be lowercase characters, and
 * there should not be any leading zeros in the answer except for the zero
 * itself.
 *
 * Note: You are not allowed to use any built-in library method to directly
 * solve this problem.
 *
 *
 * Example 1:
 * Input: num = 26
 * Output: "1a"
 * Example 2:
 * Input: num = -1
 * Output: "ffffffff"
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= num <= 2^31 - 1
 *
 *
 */

// @lc code=start

#include <stdlib.h>
#include <stdbool.h>

char* toHex(int num) {
    /* Map integer values onto corresponding hex character */
    char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

    /* String will be 8 characters max, plus NUL */
    char* str = calloc(8 + 1, sizeof(char));
    bool leading = true;

    /* Take nibble at a time, starting with most signficant */
    for (int i = 7; i >= 0; --i) {
        int nibble = (num >> (4 * i)) & 0xf;    /* Take a 4-bit group and shift it down */
        if (nibble == 0 && leading && i != 0) {
            continue;                           /* Skip leading zeroes unless it is the final nibble */
        }

        /* Add hex representation to the output */
        str[strlen(str)] = hex[nibble];
        leading = false;
    }

    return str;
}
// @lc code=end

