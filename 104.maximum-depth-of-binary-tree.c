/*
 * @lc app=leetcode id=104 lang=c
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (74.76%)
 * Likes:    12306
 * Dislikes: 204
 * Total Accepted:    2.8M
 * Total Submissions: 3.7M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return its maximum depth.
 *
 * A binary tree's maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,null,2]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -100 <= Node.val <= 100
 *
 *
 */

// @lc code=start

#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void helper(struct TreeNode *root, int level, int *maxLevel) {
    /* Break clause, no node at this level */
    if (root == NULL) {
        return;
    }

    /* Check this level */
    if (level > *maxLevel) { *maxLevel = level; }

    /* Check children now */
    helper(root->left, level + 1, maxLevel);
    helper(root->right, level + 1, maxLevel);
}

int maxDepth(struct TreeNode* root) {
    /* Track max level ever seen, and pass in root node for DFS search (considered level 1) */
    int maxLevel = 0;
    helper(root, 1, &maxLevel);

    return maxLevel;
}
// @lc code=end

