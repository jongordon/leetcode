/*
 * @lc app=leetcode id=145 lang=c
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (69.92%)
 * Likes:    6652
 * Dislikes: 183
 * Total Accepted:    1.1M
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the postorder traversal of its
 * nodes' values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
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
 * The number of the nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

// @lc code=start

#include <stdlib.h>

/* Recursive solution - trivial. Using OS stack for a stack */

// void postorder_dfs(struct TreeNode *root, int *res, int *returnSize) {
//     if (root == NULL) {
//         return;
//     }

//     postorder_dfs(root->left, res, returnSize);
//     postorder_dfs(root->right, res, returnSize);
//     res[(*returnSize)++] = root->val;
// }

// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* postorderTraversal(struct TreeNode* root, int* returnSize) {
//     *returnSize = 0;
//     int *res = malloc(100 * sizeof(*res));

//     postorder_dfs(root, res, returnSize);

//     return res;
// }


/* Iterative solution - uses an in-place stack instead */

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }


    struct TreeNode* *stack = malloc(100 * sizeof(*stack));
    int sp = 0;
    int *res = malloc(100 * sizeof(*res));
    struct TreeNode *head = root;

    stack[sp++] = head;
    while (sp > 0) {
        struct TreeNode *node = stack[sp - 1];  /* Peek, don't pop */

        /* Post-order traversal travels left -> right -> root */
        if (node->left && head != node->left && head != node->right) {
            stack[sp++] = node->left;
        }
        else if (node->right && head != node->right) {
            stack[sp++] = node->right;
        }
        else {
            --sp;
            res[(*returnSize)++] = node->val;
            head = node;
        }
    }

    return res;
}
// @lc code=end

