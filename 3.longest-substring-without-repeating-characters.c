/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (34.20%)
 * Likes:    38046
 * Dislikes: 1740
 * Total Accepted:    5.2M
 * Total Submissions: 15.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */

// @lc code=start

#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    if (s == NULL) {
        return 0;
    }

    /* Mark the index of an occurrence of an ASCII character in this array */
    int map[128] = { 0 };

    /* Keep track of max length seen, and position counting from (reset upon a duplicate) */
    int maxLength = 0, startPos = 0, currLength = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        /* If we saw this character before and index captured was after current startPos */
        if ((map[s[i]] != 0) && (map[s[i]] > startPos)) {
            /* Start counting from there now */
            startPos = map[s[i]];
        }

        /* Mark index of next character in case we need to count again */
        map[s[i]] = i + 1;

        /* Update max length */
        currLength = (i - startPos) + 1;
        if (currLength > maxLength) {
            maxLength = currLength;
        }
    }

    return maxLength;
}
// @lc code=end

