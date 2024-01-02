/*
 * @lc app=leetcode id=215 lang=c
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (66.94%)
 * Likes:    16444
 * Dislikes: 816
 * Total Accepted:    2.1M
 * Total Submissions: 3.1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Given an integer array nums and an integer k, return the k^th largest
 * element in the array.
 *
 * Note that it is the k^th largest element in the sorted order, not the k^th
 * distinct element.
 *
 * Can you solve it without sorting?
 *
 *
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
int compare(void const *a, void const *b) {
    int _a = *(int *)a;
    int _b = *(int *)b;
    if (_a < _b) { return -1; }
    if (_a > _b) { return 1; }
    return 0;
}

int findKthLargest(int* nums, int numsSize, int k) {
    /* Sort nums */
    qsort(nums, numsSize, sizeof(int), compare);
    return nums[numsSize - k];
}
// @lc code=end

