/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (75.16%)
 * Likes:    20346
 * Dislikes: 381
 * Total Accepted:    3.6M
 * Total Submissions: 4.8M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: [2,1]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 *
 *
 *
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
 *
 */

// @lc code=start

#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    /* Reverse a list by spinning the pointers around on each node, effectively, knowing the end will be NULL */
    struct ListNode *curr = head, *prev = NULL, *tmp;
    while (curr) {
        tmp = curr->next;       /* Keep a hold of the reference to the next node, it will become a previous */
        curr->next = prev;      /* Next node will point the previous node we visited (or NULL if it'll be the end) */
        prev = curr;            /* Previous node is now this node */
        curr = tmp;             /* Move onto what was the next node */
    }

    return prev;    /* We've gone over the list into NULL with curr, so we return the previous node as that's now the start */
}
// @lc code=end

