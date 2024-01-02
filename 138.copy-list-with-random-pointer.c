/*
 * @lc app=leetcode id=138 lang=c
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (54.72%)
 * Likes:    13310
 * Dislikes: 1376
 * Total Accepted:    1.1M
 * Total Submissions: 2.1M
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * A linked list of length n is given such that each node contains an
 * additional random pointer, which could point to any node in the list, or
 * null.
 *
 * Construct a deep copy of the list. The deep copy should consist of exactly n
 * brand new nodes, where each new node has its value set to the value of its
 * corresponding original node. Both the next and random pointer of the new
 * nodes should point to new nodes in the copied list such that the pointers in
 * the original list and copied list represent the same list state. None of the
 * pointers in the new list should point to nodes in the original list.
 *
 * For example, if there are two nodes X and Y in the original list, where
 * X.random --> Y, then for the corresponding two nodes x and y in the copied
 * list, x.random --> y.
 *
 * Return the head of the copied linked list.
 *
 * The linked list is represented in the input/output as a list of n nodes.
 * Each node is represented as a pair of [val, random_index] where:
 *
 *
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) that the random
 * pointer points to, or null if it does not point to any node.
 *
 *
 * Your code will only be given the head of the original linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 1000
 * -10^4 <= Node.val <= 10^4
 * Node.random is null or is pointing to some node in the linked list.
 *
 *
 */

// @lc code=start

#include <stdlib.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    /* Clone nodes inbetween original nodes:
        a -> b -> c becomes a -> a' -> b -> b' -> c -> c'
     */
    struct Node *ptr = head;
    while (ptr) {
        struct Node *new = malloc(sizeof(*new));
        new->val = ptr->val;
        new->next = ptr->next;
        ptr->next = new;

        ptr = new->next;
    }

    /* Now, we take random pointers in original list, and move them forward one.
        E.g., if a->rnd pointed at c, we can make a'->rnd point at c->next a.k.a c'
     */
    ptr = head;
    while (ptr) {
        ptr->next->random = ptr->random ? ptr->random->next : NULL;
        ptr = ptr->next->next;
    }

    /* Repair the original list without losing the new one */
    struct Node *oldHead = head;
    struct Node *newHead = head->next;
    struct Node *res = newHead;

    while (oldHead) {
        oldHead->next = oldHead->next ? oldHead->next->next : NULL;
        oldHead = oldHead->next;

        newHead->next = newHead->next ? newHead->next->next : NULL;
        newHead = newHead->next;
    }

    return res;
}
// @lc code=end

