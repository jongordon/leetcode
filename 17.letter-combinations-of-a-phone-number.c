/*
 * @lc app=leetcode id=17 lang=c
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (59.16%)
 * Likes:    17610
 * Dislikes: 922
 * Total Accepted:    1.8M
 * Total Submissions: 3.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ""
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 *
 */

// @lc code=start

#include <string.h>

/* Map string of letters agaisnt the number */
char* letters[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void backtrack(int i, char *tmp, char** res, int* pos, char* digits) {
    /* Check for end of input string, finalise combination and place in result */
    if (digits[i] == '\0') {
        tmp[i] = '\0';
        res[*pos] = malloc((strlen(digits) + 1) * sizeof(char));
        strcpy(res[*pos], tmp);
        *pos += 1;
    } else {
        /* Run through combinations for next digit */
        for (int j = 0; j < strlen(letters[digits[i] - '0']); ++j) {
            tmp[i] = letters[digits[i] - '0'][j];
            backtrack(i + 1, tmp, res, pos, digits);
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if (strlen(digits) == 0) {
        return NULL;
    }

    /* Determine the number of return results (combinations of letters from digits) */
    *returnSize = 1;
    for (int i = 0; i < strlen(digits); ++i) {
        *returnSize *= strlen(letters[digits[i] - '0']);
    }

    char** res = malloc(*returnSize * sizeof(char*));
    int pos = 0;            /* Used to track position */
    char tmp[5] = { 0 };    /* Used to hold combinations as they are built */
    backtrack(0, tmp, res, &pos, digits);

    return res;
}
// @lc code=end

