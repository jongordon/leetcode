/*
 * @lc app=leetcode id=102 lang=c
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (66.16%)
 * Likes:    14648
 * Dislikes: 290
 * Total Accepted:    2M
 * Total Submissions: 3.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: [[1]]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        returnColumnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }

    /* Allocate for worst case */
    int** res = malloc(2000 * sizeof(int*));
    *returnColumnSizes = malloc(2000 * sizeof(int));

    /* Create a worst-case queue */
    struct TreeNode* queue[2000] = { 0 };
    int head = 0, tail = 0;

    /* Start with root */
    int level = 0;
    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;    /* Number of elements at this level in the BFS */

        /* Prepare result first */
        res[level] = malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[level] = levelSize;

        /* Navigate elements */
        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode *node = queue[head++];
            res[level][i] = node->val;

            if (node->left) {
                queue[tail++] = node->left;
            }
            if (node->right) {
                queue[tail++] = node->right;
            }
        }

        /* Move to next level */
        ++level;
    }

    *returnSize = level;
    return res;
}
// @lc code=end

