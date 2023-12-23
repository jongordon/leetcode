/*
 * @lc app=leetcode id=76 lang=c
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (41.47%)
 * Likes:    16647
 * Dislikes: 681
 * Total Accepted:    1.2M
 * Total Submissions: 2.8M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 *
 * The testcases will be generated such that the answer is unique.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 *
 *
 *
 * Constraints:
 *
 *
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 *
 *
 *
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 *
 */

// @lc code=start

#include <stdint.h>

char* minWindow(char* s, char* t) {
    /* Keep track of needed characters and their frequency */
    int count[128] = { 0 };
    int need = strlen(t);
    for (int i = 0; i < need; ++i) {
        --count[t[i]];
    }

    /* Keep track of minimum length substring and start index of it */
    int smallest = INT32_MAX;
    int index = 0;

    /* Sliding window pointers */
    int l = 0;
    int r = 0;

    while (s[r]) {
        /* Did we need this character? */
        if (count[s[r]] < 0) {
            --need;
        }
        /* Mark occurred */
        ++count[s[r]];

        /* As long as the window is valid, shrink the window smaller */
        while (!need) {
            int windowSize = r - l + 1;
            if (windowSize < smallest) {
                index = l;
                smallest = windowSize;
            }

            /* Shrink the window (left no longer valid, so increase need if we were tracking it) */
            if (count[s[l]] <= 0) {
                ++need;
            }

            --count[s[l]];
            ++l;
        }

        /* Continue sliding window until we have scanned the whole string */
        ++r;
    }

    /* Did we match a substring? */
    if (smallest == INT32_MAX) {
        return "";
    }

    /* Fudge input rather than declare space for a new output */
    s[index + smallest] = '\0';
    return &s[index];
}
// @lc code=end

