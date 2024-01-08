/*
 * @lc app=leetcode id=112 lang=c
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (49.48%)
 * Likes:    9327
 * Dislikes: 1058
 * Total Accepted:    1.3M
 * Total Submissions: 2.7M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given the root of a binary tree and an integer targetSum, return true if the
 * tree has a root-to-leaf path such that adding up all the values along the
 * path equals targetSum.
 *
 * A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * Output: true
 * Explanation: The root-to-leaf path with the target sum is shown.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3], targetSum = 5
 * Output: false
 * Explanation: There two root-to-leaf paths in the tree:
 * (1 --> 2): The sum is 3.
 * (1 --> 3): The sum is 4.
 * There is no root-to-leaf path with sum = 5.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [], targetSum = 0
 * Output: false
 * Explanation: Since the tree is empty, there are no root-to-leaf paths.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
 *
 *
 */

// @lc code=start

#include <stdbool.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfsHelper(struct TreeNode *root, int sum, int targetSum, bool *res) {
    if (*res == true || !root) {
        return;
    }

    sum += root->val;
    if (sum == targetSum && !root->left && !root->right) {
        *res = true;
        return;
    }

    dfsHelper(root->left, sum, targetSum, res);
    dfsHelper(root->right, sum, targetSum, res);
}


bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }

    /* Standard DFS, with a sum being passed along? */
    bool res = false;
    int sum = 0;

    dfsHelper(root, sum, targetSum, &res);

    return res;
}
// @lc code=end

