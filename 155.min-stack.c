/*
 * @lc app=leetcode id=155 lang=c
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Medium (53.39%)
 * Likes:    13444
 * Dislikes: 818
 * Total Accepted:    1.5M
 * Total Submissions: 2.8M
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 * Implement the MinStack class:
 *
 *
 * MinStack() initializes the stack object.
 * void push(int val) pushes the element val onto the stack.
 * void pop() removes the element on the top of the stack.
 * int top() gets the top element of the stack.
 * int getMin() retrieves the minimum element in the stack.
 *
 *
 * You must implement a solution with O(1) time complexity for each
 * function.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 *
 * Output
 * [null,null,null,null,-3,null,0,-2]
 *
 * Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top();    // return 0
 * minStack.getMin(); // return -2
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= val <= 2^31 - 1
 * Methods pop, top and getMin operations will always be called on non-empty
 * stacks.
 * At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
 *
 *
 */

// @lc code=start

#include <stdlib.h>
#include <stdint.h>

typedef struct sMinStack {
    struct sMinStack *prev;
    struct sMinStack *head;
    int value;
    int minThus;
} MinStack;


MinStack* minStackCreate() {
    MinStack* stack = calloc(30000, sizeof(MinStack));
    stack->head = stack;
    stack->minThus = INT32_MAX;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    if (!obj) { return; }

    obj->head->value = val;
    obj->head->minThus = val;
    if (obj->head->prev && obj->head->prev->minThus < val) {
        obj->head->minThus = obj->head->prev->minThus;
    }

    ++obj->head;
    obj->head->prev = obj->head - 1;
}

void minStackPop(MinStack* obj) {
    if (!obj) { return; }
    obj->head = obj->head->prev;
}

int minStackTop(MinStack* obj) {
    return obj->head->prev->value;
}

int minStackGetMin(MinStack* obj) {
    return obj->head->prev->minThus;
}

void minStackFree(MinStack* obj) {
    if (!obj) { return; }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
// @lc code=end

