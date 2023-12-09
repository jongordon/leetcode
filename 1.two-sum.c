/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (51.21%)
 * Likes:    53539
 * Dislikes: 1773
 * Total Accepted:    11.6M
 * Total Submissions: 22.6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 *
 *
 *
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>

/* Store the original indices */
struct original {
    int value;
    int index;
};

/* Compare function for qsort */
int compare(void const* a, void const* b) {
    struct original* _a = (struct original*)a;
    struct original* _b = (struct original*)b;

    if (_a->value < _b->value) { return -1; }
    if (_a->value > _b->value) { return 1; }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    /* In case of failure */
    *returnSize = 0;
    if (nums == NULL || numsSize < 2) {
        return NULL;
    }

    /* Store a map of original indices as we will be sorting the values */
    struct original* map = malloc(numsSize * sizeof(struct original));
    for (int i = 0; i < numsSize; ++i) {
        map[i].value = nums[i];
        map[i].index = i;
    }

    /* Sort the map by ascending value, a simple qsort will do */
    qsort(map, numsSize, sizeof(struct original), compare);

    /* Use the two pointer method to converge on a solution with one pass */
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int sum = map[l].value + map[r].value;
        if (sum == target) {
            int* res = malloc(2 * sizeof(int));
            res[0] = map[l].index;
            res[1] = map[r].index;
            *returnSize = 2;
            return res;
        }

        /* No answer found, move pointers accordingly */
        if (sum < target) {
            ++l;
        } else {
            --r;
        }
    }

    return NULL;

}
// @lc code=end

