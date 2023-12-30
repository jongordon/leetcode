/*
 * @lc app=leetcode id=142 lang=c
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (50.33%)
 * Likes:    13026
 * Dislikes: 905
 * Total Accepted:    1.2M
 * Total Submissions: 2.4M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given the head of a linked list, return the node where the cycle begins. If
 * there is no cycle, return null.
 *
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer. Internally, pos
 * is used to denote the index of the node that tail's next pointer is
 * connected to (0-indexed). It is -1 if there is no cycle. Note that pos is
 * not passed as a parameter.
 *
 * Do not modify the linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the list is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * pos is -1 or a valid index in the linked-list.
 *
 *
 *
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
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
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    /* USe a slow and fast pointer to detect a cycle first */
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        /* Meeting pointers means a cycle */
        if (slow == fast) {
            break;
        }
    }

    /* If we hit a NULL, there is no cycle */
    if (!fast || !fast->next) {
        return NULL;
    }

    /* Now, reset one pointer and move both along at the same speed.
        They will meet at the cycle point.
        Proof:

        a = length before cycle
        b = length within cycle where slow met fast
        c = length of cycle
        d = loop count of cycle

        When they first meet: 2(a + b) == a + b + (c * d)
            i.e. fast moving at twice the speed of slow covered what slow covered plus d number of times around c
        This simplifies to a + b == c * d

        Resetting fast to the start and travelling a only: a == (c * d) - b
        In the same time, slow was b from the cycle point and travels (c * d) - b as well means b + (c * d) - b = a
        Simplified to a = (c * d) means there is no offset from the cycle point. fast has reached a, and slow has reached (c * d), conceptually
        equivalent positions.
    */
    fast = head;
    while (fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
// @lc code=end

