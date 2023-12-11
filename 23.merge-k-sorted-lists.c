/*
 * @lc app=leetcode id=23 lang=c
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (51.44%)
 * Likes:    18681
 * Dislikes: 671
 * Total Accepted:    1.8M
 * Total Submissions: 3.5M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted
 * in ascending order.
 *
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 *
 * Example 1:
 *
 *
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 *
 *
 * Example 2:
 *
 *
 * Input: lists = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: lists = [[]]
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length will not exceed 10^4.
 *
 *
 */

// @lc code=start

#include <stdio.h>
#include <stdint.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* sorted = NULL;
    struct ListNode* res = NULL;    /* Don't point at the sorted list until it is populated */

    if (listsSize == 0) {
        return res;
    }

    do {
        /* Find the starting list */
        int smallestVal = INT32_MAX, smallestList = -1;
        for (int i = 0; i < listsSize; ++i) {
            if (lists[i] != NULL) {
                if (lists[i]->val < smallestVal) {
                    smallestVal = lists[i]->val;
                    smallestList = i;
                }
            }
        }

        /* If no new list to begin from found, we can break now */
        if (smallestList == -1) {
            break;
        }

        /* Otherwise, add new node to sorted list */
        struct ListNode* new = malloc(sizeof(struct ListNode));
        if (sorted == NULL) {
            /* First time, now assign sorted */
            sorted = new;
        } else {
            sorted->next = new;
            sorted = sorted->next;
        }
        sorted->val = smallestVal;
        sorted->next = NULL;

        if (res == NULL) {
            /* First tiem, now assign res */
            res = sorted;
        }

        /* Move list along */
        lists[smallestList] = lists[smallestList]->next;
    } while (1);

    return res;
}
// @lc code=end

