/*
 * @lc app=leetcode id=100 lang=c
 *
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (60.17%)
 * Likes:    10831
 * Dislikes: 218
 * Total Accepted:    1.9M
 * Total Submissions: 3.1M
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * Given the roots of two binary trees p and q, write a function to check if
 * they are the same or not.
 *
 * Two binary trees are considered the same if they are structurally identical,
 * and the nodes have the same value.
 *
 *
 * Example 1:
 *
 *
 * Input: p = [1,2,3], q = [1,2,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: p = [1,2], q = [1,null,2]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: p = [1,2,1], q = [1,1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in both trees is in the range [0, 100].
 * -10^4 <= Node.val <= 10^4
 *
 *
 */

// @lc code=start

#include <stdbool.h>
#include <stdint.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfsHelper(struct TreeNode *p, struct TreeNode *q, bool *res) {
    if ((*res == false) || (!p && !q)) {
        return;
    }
    if (!p || !q) {
        *res = false;
        return;
    }
    if (p->val != q->val) {
        *res = false;
        return;
    }

    dfsHelper(p->left, q->left, res);
    dfsHelper(p->right, q->right, res);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    /* Recursively DFS (any order) through the trees together, ensuring they give the same output */
    if (p == NULL || q == NULL) {
        if (p == q) {
            return true;
        }
        return false;
    }

    bool res = true;
    dfsHelper(p, q, &res);
    return res;
}
// @lc code=end

