/*
 * @lc app=leetcode id=394 lang=c
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (58.67%)
 * Likes:    12185
 * Dislikes: 561
 * Total Accepted:    741.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; there are no extra
 * white spaces, square brackets are well-formed, etc. Furthermore, you may
 * assume that the original data does not contain any digits and that digits
 * are only for those repeat numbers, k. For example, there will not be input
 * like 3a or 2[4].
 *
 * The test cases are generated so that the length of the output will never
 * exceed 10^5.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 *
 *
 */

// @lc code=start
char* decodeString(char* s) {
    /* Keep track of integers */
    int *countStack = malloc(30 * sizeof(*countStack));
    int countStackPtr = 0;

    /* Keep track of strings */
    char* *stringStack = malloc(30 * sizeof(*stringStack));
    int stringStackPtr = 0;

    /* Currently built string - curse C and it's complete lack of built-in ADTs! */
    char* currentString = calloc(9000, sizeof(*currentString));
    int currentStringPtr = 0;

    int i = 0, k = 0;

    /* Walk thorugh input */
    while (s[i]) {
        if (s[i] >= '0' && s[i] <= '9') {
            /* Build up the integer (could be > 9) */
            k = (k * 10) + (s[i] - '0');
        }
        else if (s[i] == '[') {
            /* Push k to stack to keep track (could be nested) */
            countStack[countStackPtr++] = k;

            /* Push any current string to the string stack and reset it, ready for the next string to track */
            stringStack[stringStackPtr++] = strdup(currentString);
            memset(currentString, 0, 9000);
            currentStringPtr = 0;
            k = 0;
        }
        else if (s[i] == ']') {
            /* Pull out currently tracked string to add decoded current string to */
            char* decodedString = calloc(9000, sizeof(*currentString));
            strcpy(decodedString, stringStack[--stringStackPtr]);
            for (int j = countStack[--countStackPtr]; j > 0; --j) {
                strcat(decodedString, currentString);
            }
            /* Current string is tracked string until we find more data to process */
            currentString = decodedString;
            currentStringPtr = strlen(decodedString);
        }
        else {
            /* Simply add the seen character to the current string */
            currentString[currentStringPtr++] = s[i];
        }

        ++i;
    }

    return currentString;
}
// @lc code=end

