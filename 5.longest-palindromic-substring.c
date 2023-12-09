/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (33.32%)
 * Likes:    28151
 * Dislikes: 1670
 * Total Accepted:    2.8M
 * Total Submissions: 8.3M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 *
 *
 */

// @lc code=start

#include <string.h>

int expand(char* s, int left, int right) {
    /* Assuming from the center, continue outwards to check the characters match */
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        --left;
        ++right;
    }

    /* Return the count reached */
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int ans[2] = { 0 };     // Store indices

    for (int i = 0; i < strlen(s); ++i) {
        /* Starrt with odd length palindromes */
        int oddLength = expand(s, i, i);
        if (oddLength > ans[1] - ans[0] + 1) {
            /* Calculate start and end of this palindrome */
            int dist = oddLength / 2;
            ans[0] = i - dist;
            ans[1] = i + dist;
        }

        /* Even-length palindromes */
        int evenLength = expand(s, i, i + 1);
        if (evenLength > ans[1] - ans[0] + 1) {
            /* Calculate start and end of this palindrome */
            int dist = (evenLength / 2) - 1;
            ans[0] = i - dist;
            ans[1] = i + 1 + dist;
        }
    }

    /* Nullify entry after palindrome */
    s[ans[1] + 1] = '\0';
    return &s[ans[0]];
}
// @lc code=end

