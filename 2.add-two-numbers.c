/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (41.68%)
 * Likes:    29214
 * Dislikes: 5672
 * Total Accepted:    4.1M
 * Total Submissions: 9.9M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    struct ListNode* res = l3;

    if (!l1 && !l2) {
        return NULL;
    }

    /* Scan through linked lists and add together the values, mindful of a carry */
    int carry = 0;
    while (l1 || l2 || carry) {
        int a = 0, b = 0;
        if (l1) {
            a = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            b = l2->val;
            l2 = l2->next;
        }

        int sum = a + b + carry;
        if (sum > 9) {
            sum %= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        l3->val = sum;
        if (l1 || l2 || carry) {
            l3->next = malloc(sizeof(struct ListNode));
            l3 = l3->next;
        } else {
            l3->next = NULL;
        }
    }

    return res;
}
// @lc code=end

