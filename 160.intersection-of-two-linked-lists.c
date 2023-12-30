/*
 * @lc app=leetcode id=160 lang=c
 *
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (56.36%)
 * Likes:    14321
 * Dislikes: 1272
 * Total Accepted:    1.4M
 * Total Submissions: 2.5M
 * Testcase Example:  '8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3'
 *
 * Given the heads of two singly linked-lists headA and headB, return the node
 * at which the two lists intersect. If the two linked lists have no
 * intersection at all, return null.
 *
 * For example, the following two linked lists begin to intersect at node c1:
 *
 * The test cases are generated such that there are no cycles anywhere in the
 * entire linked structure.
 *
 * Note that the linked lists must retain their original structure after the
 * function returns.
 *
 * Custom Judge:
 *
 * The inputs to the judge are given as follows (your program is not given
 * these inputs):
 *
 *
 * intersectVal - The value of the node where the intersection occurs. This is
 * 0 if there is no intersected node.
 * listA - The first linked list.
 * listB - The second linked list.
 * skipA - The number of nodes to skip ahead in listA (starting from the head)
 * to get to the intersected node.
 * skipB - The number of nodes to skip ahead in listB (starting from the head)
 * to get to the intersected node.
 *
 *
 * The judge will then create the linked structure based on these inputs and
 * pass the two heads, headA and headB to your program. If you correctly return
 * the intersected node, then your solution will be accepted.
 *
 *
 * Example 1:
 *
 *
 * Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA =
 * 2, skipB = 3
 * Output: Intersected at '8'
 * Explanation: The intersected node's value is 8 (note that this must not be 0
 * if the two lists intersect).
 * From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as
 * [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are
 * 3 nodes before the intersected node in B.
 * - Note that the intersected node's value is not 1 because the nodes with
 * value 1 in A and B (2^nd node in A and 3^rd node in B) are different node
 * references. In other words, they point to two different locations in memory,
 * while the nodes with value 8 in A and B (3^rd node in A and 4^th node in B)
 * point to the same location in memory.
 *
 *
 * Example 2:
 *
 *
 * Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3,
 * skipB = 1
 * Output: Intersected at '2'
 * Explanation: The intersected node's value is 2 (note that this must not be 0
 * if the two lists intersect).
 * From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as
 * [3,2,4]. There are 3 nodes before the intersected node in A; There are 1
 * node before the intersected node in B.
 *
 *
 * Example 3:
 *
 *
 * Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB =
 * 2
 * Output: No intersection
 * Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it
 * reads as [1,5]. Since the two lists do not intersect, intersectVal must be
 * 0, while skipA and skipB can be arbitrary values.
 * Explanation: The two lists do not intersect, so return null.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes of listA is in the m.
 * The number of nodes of listB is in the n.
 * 1 <= m, n <= 3 * 10^4
 * 1 <= Node.val <= 10^5
 * 0 <= skipA < m
 * 0 <= skipB < n
 * intersectVal is 0 if listA and listB do not intersect.
 * intersectVal == listA[skipA] == listB[skipB] if listA and listB
 * intersect.
 *
 *
 *
 * Follow up: Could you write a solution that runs in O(m + n) time and use
 * only O(1) memory?
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
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    /* O(mn) solution: step through every node in List B, for every node in ListA.
        If they are equal (same pointer), this is the intersect. If none found, no intersect. */
    // struct ListNode *origB = headB;
    // while (headA) {
    //     while (headB) {
    //         if (headA == headB) {
    //             return headA;
    //         }
    //         headB = headB->next;
    //     }
    //     headB = origB;
    //     headA = headA->next;
    // }
    // return NULL;

    /* O(m+n) solution: step through every node in List A, hashing its reference (mod 30000 for problem limit) as a lookup for storing.
        For every node in ListB, do the same but check for a match in the store - if found, intersect found. If none, no intersect. */
    struct ListNode* hashmap[30000] = { 0 };
    while (headA) {
        hashmap[(long)headA % 30000] = headA;
        headA = headA->next;
    }
    while (headB) {
        if (hashmap[(long)headB % 30000] == headB) {
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}
// @lc code=end

