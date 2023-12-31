/*
 * @lc app=leetcode id=438 lang=c
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (50.58%)
 * Likes:    12014
 * Dislikes: 330
 * Total Accepted:    827.7K
 * Total Submissions: 1.6M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 *
 *
 */

// @lc code=start

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    /* Cache string lengths to avoid repeated calculations */
    int sLen = strlen(s);
    int pLen = strlen(p);

    /* If the anagram to check for is longer than the string, it's not going to have a permutation */
    if (sLen < pLen) {
        *returnSize = 0;
        return NULL;
    }

    /* Array to store indices found */
    int* res = malloc(sLen * sizeof(int));
    int index = 0;

    /* A basic "hashmap" - only 26 elements can exist so use a small array indexed by the letter found (minus its ASCII value).
        We use one for the anagram p, and one for the sliding s window */
    int pCount[26] = { 0 };
    int sCount[26] = { 0 };
    /* Build the p list now */
    for (int i = 0; i < pLen; ++i) {
        ++pCount[p[i] - 'a'];
    }

    /* Step through the string */
    for (int i = 0; i < sLen; ++i) {
        /* Add this letter to the right side of the window */
        ++sCount[s[i] - 'a'];

        /* Remove letter from the left side of the window */
        if (i >= pLen) {
            --sCount[s[(i - pLen)] - 'a'];
        }

        /* Compare the "hashmaps" to see if an anagram/match has been found in the window */
        int j = 0;
        for ( ; j < 26; ++j) {
            if (pCount[j] != sCount[j]) {
                break;
            }
        }
        if (j == 26) {
            res[index++] = i - pLen + 1;    /* We have gone past the anagram to have detected it, so back the index to the start of it */
        }
    }

    *returnSize = index;
    return res;
}
// @lc code=end

