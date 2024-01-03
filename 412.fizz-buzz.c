/*
 * @lc app=leetcode id=412 lang=c
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (71.27%)
 * Likes:    2551
 * Dislikes: 336
 * Total Accepted:    1.1M
 * Total Submissions: 1.6M
 * Testcase Example:  '3'
 *
 * Given an integer n, return a string array answer (1-indexed) where:
 *
 *
 * answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * answer[i] == "Fizz" if i is divisible by 3.
 * answer[i] == "Buzz" if i is divisible by 5.
 * answer[i] == i (as a string) if none of the above conditions are true.
 *
 *
 *
 * Example 1:
 * Input: n = 3
 * Output: ["1","2","Fizz"]
 * Example 2:
 * Input: n = 5
 * Output: ["1","2","Fizz","4","Buzz"]
 * Example 3:
 * Input: n = 15
 * Output:
 * ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */

// @lc code=start

#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char* *res = malloc(n * sizeof(*res));
    for (int i = 1; i <= n; ++i) {
        /* Each entry could be upto 9 characters long (FizzBuzz + NUL) */
        res[i - 1] = calloc(9, sizeof(char));

        /* Determine string to enter here */
        if (i % 3 == 0) {
            strcpy(res[i - 1], "Fizz");
        }
        if (i % 5 == 0) {
            strcpy(&res[i - 1][strlen(res[i - 1])], "Buzz");
        }
        if (i % 3 && i % 5) {
            sprintf(res[i - 1], "%d", i);
        }
    }
    *returnSize = n;
    return res;
}
// @lc code=end

