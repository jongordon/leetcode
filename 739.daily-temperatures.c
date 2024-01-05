/*
 * @lc app=leetcode id=739 lang=c
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (65.90%)
 * Likes:    12075
 * Dislikes: 275
 * Total Accepted:    770K
 * Total Submissions: 1.2M
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 *
 *
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    /* Brute force approach - time limit exceeded. But showing here for the simplicity of the problem */

    // int *answer = calloc(temperaturesSize, sizeof(*answer));
    // *returnSize = temperaturesSize;

    // for (int i = 0; i < temperaturesSize; ++i) {
    //     int wait = 0;
    //     for (int j = i + 1; j < temperaturesSize; ++j) {
    //         if (temperatures[j] > temperatures[i]) {
    //             wait = j - i;
    //             break;
    //         }
    //     }
    //     answer[i] = wait;
    // }

    // return answer;


    /* Using a stack as is intended by the nature of the problem constraints (up to 10^5 elements) */

    int *answer = calloc(temperaturesSize, sizeof(*answer));
    *returnSize = temperaturesSize;

    int hottest = 0;

    for (int i = temperaturesSize - 1; i >= 0; --i) {
        int temp = temperatures[i];
        if (temp >= hottest) {
            hottest = temp;
            continue;
        }

        int wait = 1;
        while (temperatures[wait + i] <= temp) {
            wait += answer[wait + i];
        }
        answer[i] = wait;
    }

    return answer;
}
// @lc code=end

