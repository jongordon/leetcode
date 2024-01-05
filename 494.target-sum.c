/*
 * @lc app=leetcode id=494 lang=c
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (46.28%)
 * Likes:    10479
 * Dislikes: 345
 * Total Accepted:    542.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * You are given an integer array nums and an integer target.
 *
 * You want to build an expression out of nums by adding one of the symbols '+'
 * and '-' before each integer in nums and then concatenate all the
 * integers.
 *
 *
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1
 * and concatenate them to build the expression "+2-1".
 *
 *
 * Return the number of different expressions that you can build, which
 * evaluates to target.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,1,1], target = 3
 * Output: 5
 * Explanation: There are 5 ways to assign symbols to make the sum of nums be
 * target 3.
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], target = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 *
 *
 */

// @lc code=start
void dfs(int* nums, int level, int maxLevel, int sum, int target, int* solutions) {
    if (level == maxLevel) {
        if (sum == target) {
            ++(*solutions);
        }
        return;
    }

    int thisNum = nums[++level];
    dfs(nums, level, maxLevel, sum + thisNum, target, solutions);
    dfs(nums, level, maxLevel, sum - thisNum, target, solutions);
}

int findTargetSumWays(int* nums, int numsSize, int target) {
    int solutions = 0;

    dfs(nums, -1, numsSize - 1, 0, target, &solutions);

    return solutions;
}
// @lc code=end

