/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (75.12%)
 * Likes:    13012
 * Dislikes: 729
 * Total Accepted:    2.4M
 * Total Submissions: 3.1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// void helper(struct TreeNode *root, int *order, int *returnSize) {
//     if (root) {
//         helper(root->left, order, returnSize);
//         order[*returnSize] = root->val;
//         ++(*returnSize);
//         helper(root->right, order, returnSize);
//     }
// }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    /* This and helper function is a recursive solution - trivial. */

    // *returnSize = 0;
    // if (!root) {
    //     return NULL;
    // }

    // int *order = malloc(101 * sizeof(*order));
    // helper(root, order, returnSize);

    // return order;


    /* Ideally, we solve this with a custom stack - let's not blow the system one with recursion */

    *returnSize = 0;
    int *order = malloc(101 * sizeof(*order));
    struct TreeNode* *stack = malloc(101 * sizeof(*stack));
    struct TreeNode *curr = root;
    int tail = -1;

    while (curr != NULL || tail != -1) {
        while (curr != NULL) {
            stack[++tail] = curr;
            curr = curr->left;
        }
        curr = stack[tail--];
        order[(*returnSize)++] = curr->val;
        curr = curr->right;
    }

    return order;
}
// @lc code=end

