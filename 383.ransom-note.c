/*
 * @lc app=leetcode id=383 lang=c
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (60.07%)
 * Likes:    4726
 * Dislikes: 482
 * Total Accepted:    994K
 * Total Submissions: 1.6M
 * Testcase Example:  '"a"\n"b"'
 *
 * Given two strings ransomNote and magazine, return true if ransomNote can be
 * constructed by using the letters from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once in ransomNote.
 *
 *
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote and magazine consist of lowercase English letters.
 *
 *
 */

// @lc code=start

#include <stdbool.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine) {
    /* Simple frequency count */
    int freq[26] = { 0 };

    for (int i = 0; i < strlen(magazine); ++i) {
        ++freq[magazine[i] - 'a'];
    }
    for (int i = 0; i < strlen(ransomNote); ++i) {
        --freq[ransomNote[i] - 'a'];
        if (freq[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }

    return true;
}
// @lc code=end

