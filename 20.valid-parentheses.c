/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.24%)
 * Likes:    22799
 * Dislikes: 1586
 * Total Accepted:    4M
 * Total Submissions: 10M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(]"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 *
 *
 */

// @lc code=start

#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    int stack[len];
    int sp = -1;

    for (int i = 0; i < len; ++i) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            /* Push opening bracket to stack */
            stack[++sp] = s[i];
        } else {
            if (sp == -1) {
                return false;   /* Early exit for unmatched closing bracket */
            }
            if ((s[i] == '}' && stack[sp] == '{') ||
                (s[i] == ']' && stack[sp] == '[') ||
                (s[i] == ')' && stack[sp] == '(')) {
                /* Matching close for an opened bracket */
                --sp;
            } else {
                /* Unmatched close */
                return false;
            }
        }
    }

    /* Final check - all elements popped? */
    return (sp == -1);
}
// @lc code=end

