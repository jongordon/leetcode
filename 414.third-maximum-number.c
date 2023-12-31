/*
 * @lc app=leetcode id=414 lang=c
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (34.15%)
 * Likes:    2889
 * Dislikes: 3036
 * Total Accepted:    492.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,2,1]'
 *
 * Given an integer array nums, return the third distinct maximum number in
 * this array. If the third maximum does not exist, return the maximum
 * number.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,2,1]
 * Output: 1
 * Explanation:
 * The first distinct maximum is 3.
 * The second distinct maximum is 2.
 * The third distinct maximum is 1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2]
 * Output: 2
 * Explanation:
 * The first distinct maximum is 2.
 * The second distinct maximum is 1.
 * The third distinct maximum does not exist, so the maximum (2) is returned
 * instead.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [2,2,3,1]
 * Output: 1
 * Explanation:
 * The first distinct maximum is 3.
 * The second distinct maximum is 2 (both 2's are counted together since they
 * have the same value).
 * The third distinct maximum is 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow up: Can you find an O(n) solution?
 */

// @lc code=start

#include <stdint.h>

int compare(void const *a, void const *b) {
    int _a = *(int*)a;
    int _b = *(int*)b;

    if (_a < _b) { return 1; }
    if (_a > _b) { return -1; }
    return 0;
}

int thirdMax(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    } else if (numsSize == 2) {
        return nums[0] > nums[1] ? nums [0] : nums[1];
    }

    /* Method 1: Sorting - makes finding the largest easy if they're in order.
        34/34 cases passed (5 ms)
        Your runtime beats 73.91 % of c submissions
        Your memory usage beats 66.67 % of c submissions (6.9 MB)
    */

    // /* Sort the array (decreasing) to find the third maximum number easily */
    // qsort(nums, numsSize, sizeof(int), compare);

    // /* Need to find three distinct values to satisfy problem */
    // int counted = 1;
    // int previous = nums[0];
    // for (int i = 1; i < numsSize; ++i) {
    //     if (nums[i] != previous) {
    //         ++counted;
    //         previous = nums[i];
    //     }

    //     if (counted == 3) {
    //         return previous;
    //     }
    // }

    // /* We haven't found the third largest, so return the largest */
    // return nums[0];

    /* Method 2: Three pointers
        34/34 cases passed (7 ms)
        Your runtime beats 32.85 % of c submissions
        Your memory usage beats 80.19 % of c submissions (6.7 MB)
     Should clearly be quicker than doing a sort but evidently not - or Leetcode servers are unreliable */

    /* Use three pointers with values less than the possible least value */
    long first = INT64_MIN, second = INT64_MIN, third = INT64_MIN;

    for (int i = 0; i < numsSize; ++i) {
        int check = nums[i]; // Cache 9 lookups into 1 (probably already done by compiler but jic)

        /* If we have alreacdy seen this number, skip it */
        if (check == first || check == second || check == third) {
            continue;
        }

        /* New maximum seen, shift others down accordingly */
        if (check > first) {
            third = second;
            second = first;
            first = check;
        }
        else if (check > second) {
            third = second;
            second = check;
        }
        else if (check > third) {
            third = check;
        }
        else {
            /* Do nothing */
        }
    }

    /* Did we have three maximums? */
    int ans;
    if (third == INT64_MIN) {
        ans = (int)first;
    }
    else {
        ans = (int)third;
    }

    return ans;
}
// @lc code=end

