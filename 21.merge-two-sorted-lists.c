/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (63.48%)
 * Likes:    20630
 * Dislikes: 1935
 * Total Accepted:    3.7M
 * Total Submissions: 5.9M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * You are given the heads of two sorted linked lists list1 and list2.
 *
 * Merge the two lists into one sorted list. The list should be made by
 * splicing together the nodes of the first two lists.
 *
 * Return the head of the merged linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 *
 * Example 2:
 *
 *
 * Input: list1 = [], list2 = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both list1 and list2 are sorted in non-decreasing order.
 *
 *
 */

// @lc code=start

#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }

    struct ListNode* list3 = malloc(sizeof(struct ListNode));
    struct ListNode* res = list3;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            list3->next = list1;
            list1 = list1->next;
        } else {
            list3->next = list2;
            list2 = list2->next;
        }
        list3 = list3->next;
    }

    if (list1) {
        list3->next = list1;
    } else {
        list3->next = list2;
    }

    return res->next;
}
// @lc code=end

