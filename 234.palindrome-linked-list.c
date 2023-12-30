/*
 * @lc app=leetcode id=234 lang=c
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (51.31%)
 * Likes:    15611
 * Dislikes: 839
 * Total Accepted:    1.7M
 * Total Submissions: 3.2M
 * Testcase Example:  '[1,2,2,1]'
 *
 * Given the head of a singly linked list, return true if it is a palindrome or
 * false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,2,1]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 10^5].
 * 0 <= Node.val <= 9
 *
 *
 *
 * Follow up: Could you do it in O(n) time and O(1) space?
 */

// @lc code=start
#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    // /* Brute force this - copy elements as the list is walked into an array we can more easily check for a palindrome */
    // uint8_t* array = malloc(100000 * sizeof(uint8_t));   /* We know node values are only 0...10 (uint8_t) but can be up to 10^5 of them */
    // int i = 0;

    // while (head) {
    //     array[i++] = head->val;
    //     head = head->next;
    // }

    // /* Now we have the values in an array, and its size,
    //     we can run two pointers together to check for a palindrome */
    // int l = 0, r = i - 1;
    // while (l <= r) {
    //     /* If the values don't match, it's not a palindrome */
    //     if (array[l] != array[r]) {
    //         return false;
    //     }
    //     ++l;
    //     --r;
    // }

    // /* If we reached this point, all numbers matched == palindrome */
    // return true;

    /* Alternative solution (far better space complexity) using two pointers again,
        but slow and fast to find end and mid-point without having to copy out */
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse the second half (from slow onwards) */
    struct ListNode *temp = NULL, *prev = NULL;
    while (slow) {
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    /* Now compare both halves together - should be equal at every step if originally a palindrome */
    while (prev) {
        if (head->val != prev->val) {
            return false;
        }
        head = head->next;
        prev = prev->next;
    }

    return true;
}
// @lc code=end

