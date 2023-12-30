/*
 * @lc app=leetcode id=189 lang=c
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Medium (40.02%)
 * Likes:    16955
 * Dislikes: 1844
 * Total Accepted:    1.9M
 * Total Submissions: 4.7M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an integer array nums, rotate the array to the right by k steps, where
 * k is non-negative.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,-100,3,99], k = 2
 * Output: [3,99,-1,-100]
 * Explanation:
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^5
 *
 *
 *
 * Follow up:
 *
 *
 * Try to come up with as many solutions as you can. There are at least three
 * different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 *
 *
 */

// @lc code=start
void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0 || numsSize == k) {
        return;     /* Nothing to do */
    }

    /* Rationalise multiple whole-loop rotations */
    k %= numsSize;

    /* Rotating is the same as moving by k, and prepending all lost values.
        Let a = everything from [0] to [len-1-k]
        Let b = everything from [len-1-k] to [len-1].
        Store a while b is copied onto [0].
        Copy a onto [k]
     */
    int aLen = numsSize - k;
    int* a = calloc(aLen, sizeof(int));
    memcpy(a, &nums[0], aLen * sizeof(int));

    int bLen = k;
    int* b = calloc(bLen, sizeof(int));
    memcpy(b, &nums[aLen], bLen * sizeof(int));

    memcpy(&nums[0], b, bLen * sizeof(int));
    memcpy(&nums[bLen], a, aLen * sizeof(int));
}
// @lc code=end

