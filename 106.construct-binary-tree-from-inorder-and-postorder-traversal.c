/*
 * @lc app=leetcode id=106 lang=c
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (61.72%)
 * Likes:    7761
 * Dislikes: 124
 * Total Accepted:    595.1K
 * Total Submissions: 960.7K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given two integer arrays inorder and postorder where inorder is the inorder
 * traversal of a binary tree and postorder is the postorder traversal of the
 * same tree, construct and return the binary tree.
 *
 *
 * Example 1:
 *
 *
 * Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * Output: [3,9,20,null,null,15,7]
 *
 *
 * Example 2:
 *
 *
 * Input: inorder = [-1], postorder = [-1]
 * Output: [-1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder and postorder consist of unique values.
 * Each value of postorder also appears in inorder.
 * inorder is guaranteed to be the inorder traversal of the tree.
 * postorder is guaranteed to be the postorder traversal of the tree.
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
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    /* We also know left subtree and right subtree from inorder traversal (left and right of root)
        Removing root from postorder gives next root (like a stack) which can then be used again to get left and right subtrees
        and so on. Use a DFS recursion. */
    if (inorderSize == 0) {
        return NULL;
    }

    /* Extract next root from end of postorder */
    struct TreeNode *root = malloc(sizeof(*root));
    root->val = postorder[postorderSize - 1];

    /* Find same root in inorder */
    int rootIndex = 0;
    while (inorder[rootIndex] != root->val) {
        ++rootIndex;
    }

    /* Now build left and right subtrees from new bounds */
    root->left  = buildTree(&inorder[0], rootIndex, &postorder[0], rootIndex);
    root->right = buildTree(&inorder[rootIndex + 1], (inorderSize - 1) - rootIndex, &postorder[rootIndex], (inorderSize - 1) - rootIndex);

    return root;
}
// @lc code=end

