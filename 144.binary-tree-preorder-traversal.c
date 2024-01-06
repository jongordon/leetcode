/*
 * @lc app=leetcode id=144 lang=c
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (68.57%)
 * Likes:    7724
 * Dislikes: 198
 * Total Accepted:    1.5M
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the preorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
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

/* Recursive solution - trivial. Using OS stack for a stack */

// void preorder_dfs(struct TreeNode *root, int *res, int *returnSize) {
//     if (root == NULL) {
//         return;
//     }

//     res[(*returnSize)++] = root->val;
//     preorder_dfs(root->left, res, returnSize);
//     preorder_dfs(root->right, res, returnSize);
// }

// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//     *returnSize = 0;
//     int *res = malloc(100 * sizeof(*res));

//     preorder_dfs(root, res, returnSize);

//     return res;
// }


/* Iterative solution - uses an in-place stack instead */

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* *stack = malloc(100 * sizeof(*stack));
    int sp = 0;
    int *res = malloc(100 * sizeof(*res));

    stack[sp++] = root;
    while (sp > 0) {
        /* Pre-order traversal travels root -> left -> right */
        struct TreeNode *node = stack[--sp];
        res[(*returnSize)++] = node->val;

        /* But we push right first as a stack is LIFO (so it'll be traversed left, right) */
        if (node->right) {
            stack[sp++] = node->right;
        }
        if (node->left) {
            stack[sp++] = node->left;
        }
    }

    return res;
}

// @lc code=end

