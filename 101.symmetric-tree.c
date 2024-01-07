/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (55.64%)
 * Likes:    14755
 * Dislikes: 359
 * Total Accepted:    1.9M
 * Total Submissions: 3.3M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Could you solve it both recursively and iteratively?
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
bool isSymmetric(struct TreeNode* root) {
    /* Worst-case queue */
    struct TreeNode* *queue = malloc(1000 * sizeof(*queue));
    int head = 0, tail = 0;

    /* Add two roots to queue first, using BFS to determine equal subtrees at a common node */
    queue[tail++] = root;
    queue[tail++] = root;

    /* Walk the queue (FIFO) */
    while (head < tail) {
        struct TreeNode *nodeA = queue[head++];
        struct TreeNode *nodeB = queue[head++];

        if (nodeA == NULL && nodeB == NULL) {
            /* Continue checking more nodes, if we can */
            continue;
        }
        if (nodeA == NULL || nodeB == NULL) {
            /* Can't be a mirror if only one tree has ended */
            return false;
        }
        if (nodeA->val != nodeB->val) {
            /* Can't be a mirror if nodes don't match */
            return false;
        }

        /* Add nodes for subtrees in mirror order */
        queue[tail++] = nodeA->left;
        queue[tail++] = nodeB->right;
        queue[tail++] = nodeA->right;
        queue[tail++] = nodeB->left;
    }

    free(queue);
    return true;
}
// @lc code=end

