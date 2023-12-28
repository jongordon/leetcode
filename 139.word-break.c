/*
 * @lc app=leetcode id=139 lang=c
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (46.39%)
 * Likes:    16583
 * Dislikes: 724
 * Total Accepted:    1.6M
 * Total Submissions: 3.4M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary
 * words.
 *
 * Note that the same word in the dictionary may be reused multiple times in
 * the segmentation.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 *
 *
 */

// @lc code=start

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool inDictionary(char** dictionary, int numEntries, char* inputStr) {
    for (int i = 0; i < numEntries; ++i) {
        if (strcmp(inputStr, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

char* substring(char* string, int start, int count) {
    char* substr = calloc(count + 1, sizeof(char));
    memcpy(substr, &string[start], count);
    return substr;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    if (wordDict == NULL || s == NULL) {
        return false;
    }

    bool result = false;
    int pos = 0;

    for (int i = 0; i < strlen(s); ++i) {
        char* substr = substring(s, pos, i + 1 - pos);
        if (inDictionary(wordDict, wordDictSize, substr)) {
            /* Valid substring so far, check the rest of the string */
            pos = i + 1;
        }
    }

    if (pos == strlen(s)) {
        result = true;
    }

    return result;
}
// @lc code=end

