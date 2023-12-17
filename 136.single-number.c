/*
 * @lc app=leetcode id=136 lang=c
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (71.92%)
 * Likes:    15700
 * Dislikes: 651
 * Total Accepted:    2.5M
 * Total Submissions: 3.5M
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 *
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 *
 *
 * Example 1:
 * Input: nums = [2,2,1]
 * Output: 1
 * Example 2:
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * Example 3:
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * Each element in the array appears twice except for one element which appears
 * only once.
 *
 *
 */

// @lc code=start

#include <stdint.h>

int singleNumber(int* nums, int numsSize) {
    uint32_t sum = nums[0];

    /* Simply XOR all the digits in the array together - each pair will cancel out leaving the odd-one-out */
    for (int i = 1; i < numsSize; ++i) {
        sum ^= nums[i];
    }

    return sum;
}
// @lc code=end

