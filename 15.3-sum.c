/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (33.68%)
 * Likes:    29247
 * Dislikes: 2660
 * Total Accepted:    3.1M
 * Total Submissions: 9.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start

#include <stdio.h>

int compare(const void* a, const void* b) {
    int _a = *(const int*)a;
    int _b = *(const int*)b;

    if (_a < _b) { return -1; }
    if (_a > _b) { return 1; }
    return 0;
}

void twoSum(int* nums, int numsSize, int i, int** res, int* returnSize, int** returnColumnSizes) {
    /* Start at next element after the current one */
    int lo = i + 1, hi = numsSize - 1;

    /* Run two pointer solver for problem */
    while (lo < hi) {
        int sum = nums[lo] + nums[hi] + nums[i];
        if (sum < 0) {
            ++lo;
        } else if (sum > 0) {
            --hi;
        } else {
            /* Found a valid triplet */
            res[(*returnSize)] = malloc(3 * sizeof(int));
            (*returnColumnSizes)[(*returnSize)] = 3;
            res[(*returnSize)][0] = nums[i];
            res[(*returnSize)][1] = nums[lo];
            res[(*returnSize)][2] = nums[hi];
            ++(*returnSize);
            ++lo;

            /* Avoid duplicates with other same lo values */
            while ((lo < hi) && (nums[lo] == nums[lo - 1])) {
                ++lo;
            }
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    /* An extension of the two sum problem */
    if ((nums == NULL) || (numsSize < 3)) {
        return NULL;
    }

    /* Sort the array, start at [0] and two sum the rest of the array, and continue upwards. */
    qsort(nums, numsSize, sizeof(int), compare);

    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));
    int** res = malloc(numsSize * numsSize * sizeof(int*));

    for (int i = 0; i < numsSize; ++i) {
        /* If we have hit positive integers, it won't be possible to come up with a solution */
        if (nums[i] > 0) {
            break;
        }

        /* No point checking the same number again */
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        /* Run twoSum on remaining numbers */
        twoSum(nums, numsSize, i, res, returnSize, returnColumnSizes);
    }

    return res;
}
// @lc code=end

