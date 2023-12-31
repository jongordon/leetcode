/*
 * @lc app=leetcode id=242 lang=c
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (63.51%)
 * Likes:    11489
 * Dislikes: 364
 * Total Accepted:    3M
 * Total Submissions: 4.7M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */

// @lc code=start

#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    /* Multiple approaches to this. Sort both and compare, hashmap, freq count, etc.
        As the constraint says all strings are lowercase letters, that suggests they're looking for a simple freq count.
        Freq count is a basic hashmap as just an array - only 26 unique elements */
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int hashmap[26] = { 0 };

    for (int i = 0; i < strlen(s); ++i) {
        ++hashmap[s[i] - 'a'];
        --hashmap[t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (hashmap[i] != 0) {
            return false;
        }
    }

    return true;
}
// @lc code=end

