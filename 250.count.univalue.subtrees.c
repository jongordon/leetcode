/** Premium exercise so not in VSCode plugin **/

/*
Given the root of a binary tree, return the number of uni-value
subtrees
.

A uni-value subtree means all nodes of the subtree have the same value.



Example 1:


Input: root = [5,1,5,5,5,null,5]
Output: 4
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [5,5,5,5,5,null,5]
Output: 6


Constraints:

The number of the node in the tree will be in the range [0, 1000].
-1000 <= Node.val <= 1000
*/

#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkSubtree(struct TreeNode *root, int *count) {
    if (!root) {
        return true;
    }

    bool leftValid = checkSubtree(root->left, count);
    bool rightValid = checkSubtree(root->right, count);

    if (leftValid && rightValid) {
        if (root->left && root->left->val != root->val) {
            return false;
        }
        if (root->right && root->right->val != root->val) {
            return false;
        }

        /* Otherwise, valid subtree */
        ++(*count);
        return true;
    }

    return false;
}

int countUnivalSubtrees(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int ans = 0;
    checkSubtree(root, &ans);
    return ans;
}