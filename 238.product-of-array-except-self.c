/*
 * @lc app=leetcode id=238 lang=c
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (65.12%)
 * Likes:    20909
 * Dislikes: 1214
 * Total Accepted:    2.1M
 * Total Submissions: 3.2M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 *
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 *
 *
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The
 * output array does not count as extra space for space complexity analysis.)
 *
 */

// @lc code=start

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = calloc(numsSize, sizeof(int));
    int* left   = calloc(numsSize, sizeof(int));
    int* right  = calloc(numsSize, sizeof(int));

    /* Construct LHS */
    left[0] = 1;
    for (int i = 1; i < numsSize; ++i) {
        left[i] = nums[i - 1] * left[i - 1];
    }

    /* Construct RHS */
    right[numsSize - 1] = 1;
    for (int i = numsSize - 2; i >= 0; --i) {
        right[i] = nums[i + 1] * right[i + 1];
    }

    /* Construct answer as products of left and right (as they've now skipped self values) */
    for (int i = 0; i < numsSize; ++i) {
        answer[i] = left[i] * right[i];
    }

    *returnSize = numsSize;
    return answer;
}
// @lc code=end

