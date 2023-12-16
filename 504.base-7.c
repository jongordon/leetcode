/*
 * @lc app=leetcode id=504 lang=c
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (49.41%)
 * Likes:    760
 * Dislikes: 221
 * Total Accepted:    121.3K
 * Total Submissions: 245.3K
 * Testcase Example:  '100'
 *
 * Given an integer num, return a string of its base 7 representation.
 *
 *
 * Example 1:
 * Input: num = 100
 * Output: "202"
 * Example 2:
 * Input: num = -7
 * Output: "-10"
 *
 *
 * Constraints:
 *
 *
 * -10^7 <= num <= 10^7
 *
 *
 */

// @lc code=start

#include <stdbool.h>
#include <math.h>

char* convertToBase7(int num) {
    if (num == 0) {
        return "0";
    }

    int ans = 0;
    int temp = 1;   /* Track the decimal columns, starting with 10^0 (1) */

    while (num != 0) {
        ans += temp * (num % 7);    /* Take the remainder of 7 for the equivalent decimal column */
        num /= 7;                   /* Move onto the next 7^x column */
        temp *= 10;                 /* Move onto next decimal column, 10^1, 10^2, etc */
    }

    char* str = malloc(20 * sizeof(char));
    sprintf(str, "%i", ans);

    return str;
}
// @lc code=end

