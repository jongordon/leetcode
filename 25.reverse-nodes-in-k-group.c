/*
 * @lc app=leetcode id=25 lang=c
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (57.17%)
 * Likes:    13016
 * Dislikes: 642
 * Total Accepted:    832.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, reverse the nodes of the list k at a time,
 * and return the modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes, in the end, should remain as it is.
 *
 * You may not alter the values in the list's nodes, only nodes themselves may
 * be changed.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is n.
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 *
 *
 *
 * Follow-up: Can you solve the problem in O(1) extra memory space?
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

struct ListNode* reverseList(struct ListNode *head, int count) {
    struct ListNode *curr = head, *prev = NULL, *tmp;

    for (int i = 0; i < count; ++i) {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }

    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    /* General approach to this problem is reversing a single linked list multiple times,
        noting each time that the list is severed so "sub-lists" need stitching together.
        Any potential sub-list that isn't a full multiple of k is left as-is. */

    /* Keep track of curr, prev, and intermediate "prev" which we call subPrev */
    struct ListNode *curr = head, *prev = NULL, *subPrev = NULL;

    /* Until we have parsed the lsit */
    while (curr) {
        /* Firstly count if we have a full k nodes to reverse, moving curr at the same time */
        int count = 0;
        while (count < k && curr) {
            curr = curr->next;
            ++count;
        }

        /* Did we get a full k? */
        if (count == k) {
            /* Reverse the k elements seen since head was updated, holding onto this sub-list head returned */
            struct ListNode *subCurr = reverseList(head, k);

            /* If we have never tracked a new entry point, this first one is the new entry */
            if (!prev) {
                prev = subCurr;
            }

            /* If we had a previous sub-list, it will need to be stitched to this new sub-list */
            if (subPrev) {
                subPrev->next = subCurr;
            }

            /* Store old head as previous sub-list before updating it as it's now just before any further lists */
            subPrev = head;
            head = curr;
        }
    }

    /* Stitch on head as anything else left alone or we're at NULL */
    if (subPrev) {
        subPrev->next = head;
    }

    /* If we ever tracked a new reverse entry point, we return that; otherwise the original list */
    return prev ? prev : head;
}
// @lc code=end

