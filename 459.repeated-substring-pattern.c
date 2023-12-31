/*
 * @lc app=leetcode id=459 lang=c
 *
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (46.06%)
 * Likes:    6232
 * Dislikes: 497
 * Total Accepted:    419.6K
 * Total Submissions: 911.1K
 * Testcase Example:  '"abab"'
 *
 * Given a string s, check if it can be constructed by taking a substring of it
 * and appending multiple copies of the substring together.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abab"
 * Output: true
 * Explanation: It is the substring "ab" twice.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aba"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: s = "abcabcabcabc"
 * Output: true
 * Explanation: It is the substring "abc" four times or the substring "abcabc"
 * twice.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of lowercase English letters.
 *
 *
 */

// @lc code=start

#include <stdbool.h>
#include <stdint.h>

bool repeatedSubstringPattern(char* s) {
    /* Trick: not an "easy" question at all! Effectively, rely on the fact that a rotation of s is valid if made of repeated substrings.
        We check for rotations of strings with two copies - this naturally contain all possible rotations.
        Remove first and last letters and then test for original s inside this new concat string. */

    // int sLen = strlen(s);
    // char* t = malloc((sLen * 2) * sizeof(char));
    // strcpy(t, s);
    // strncat(t, s, sLen - 1);    /* Skip last letter */
    // ++t;                        /* Skip first letter */

    // if (strstr(t, s)) {
    //     /* Substring found */
    //     return true;
    // }

    // return false;

    /* "Normal" solution is to run through a number of equal divisors in the string */

    int n = strlen(s);
    for (int i = 1; i <= n / 2; i++) {
        /* Equal divisor: */
        if (n % i == 0) {
            /* Build a repeated pattern of substrings of length i */
            char* pattern = calloc(n + 1, sizeof(char));
            for (int j = 0; j < n; j += i) {
                memcpy(&pattern[j], &s[0], i);
            }
            /* Verify s matches the pattern */
            bool matching = true;
            for (int j = 0; j < n; ++j) {
                if (pattern[j] != s[j]) {
                    matching = false;
                    break;
                }
            }
            free(pattern);
            if (matching) {
                return true;
            }
        }
    }
    return false;
}
// @lc code=end

