/*
 * @lc app=leetcode id=98 lang=c
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (32.51%)
 * Likes:    16132
 * Dislikes: 1315
 * Total Accepted:    2.1M
 * Total Submissions: 6.6M
 * Testcase Example:  '[2,1,3]'
 *
 * Given the root of a binary tree, determine if it is a valid binary search
 * tree (BST).
 *
 * A valid BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [2,1,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is
 * 4.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 */

// @lc code=start

#include <stdio.h>
#include <stdbool.h>

bool validate(struct TreeNode* root, struct TreeNode* low, struct TreeNode* high) {
    /* Empty = valid */
    if (root == NULL) {
        return true;
    }

    /* If low value is higher than root, the tree is invalid.
    Likewise if root is lower than high, it's also invalid */
    if ((low && root->val <= low->val) || (high && root->val >= high->val)) {
        return false;
    }

    /* Continue for subtrees as well - they must also be valid */
    bool left = validate(root->left, low, root);
    bool right = validate(root->right, root, high);

    return left && right;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) {
    return validate(root, NULL, NULL);
}
// @lc code=end

