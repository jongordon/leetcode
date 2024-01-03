/*
 * @lc app=leetcode id=622 lang=c
 *
 * [622] Design Circular Queue
 *
 * https://leetcode.com/problems/design-circular-queue/description/
 *
 * algorithms
 * Medium (51.33%)
 * Likes:    3420
 * Dislikes: 267
 * Total Accepted:    294.8K
 * Total Submissions: 574.2K
 * Testcase Example:  '["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]\n' +
  '[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * Design your implementation of the circular queue. The circular queue is a
 * linear data structure in which the operations are performed based on FIFO
 * (First In First Out) principle, and the last position is connected back to
 * the first position to make a circle. It is also called "Ring Buffer".
 *
 * One of the benefits of the circular queue is that we can make use of the
 * spaces in front of the queue. In a normal queue, once the queue becomes
 * full, we cannot insert the next element even if there is a space in front of
 * the queue. But using the circular queue, we can use the space to store new
 * values.
 *
 * Implement the MyCircularQueue class:
 *
 *
 * MyCircularQueue(k) Initializes the object with the size of the queue to be
 * k.
 * int Front() Gets the front item from the queue. If the queue is empty,
 * return -1.
 * int Rear() Gets the last item from the queue. If the queue is empty, return
 * -1.
 * boolean enQueue(int value) Inserts an element into the circular queue.
 * Return true if the operation is successful.
 * boolean deQueue() Deletes an element from the circular queue. Return true if
 * the operation is successful.
 * boolean isEmpty() Checks whether the circular queue is empty or not.
 * boolean isFull() Checks whether the circular queue is full or not.
 *
 *
 * You must solve the problem without using the built-in queue data structure
 * in your programming language. 
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear",
 * "isFull", "deQueue", "enQueue", "Rear"]
 * [[3], [1], [2], [3], [4], [], [], [], [4], []]
 * Output
 * [null, true, true, true, false, 3, true, true, true, 4]
 *
 * Explanation
 * MyCircularQueue myCircularQueue = new MyCircularQueue(3);
 * myCircularQueue.enQueue(1); // return True
 * myCircularQueue.enQueue(2); // return True
 * myCircularQueue.enQueue(3); // return True
 * myCircularQueue.enQueue(4); // return False
 * myCircularQueue.Rear();     // return 3
 * myCircularQueue.isFull();   // return True
 * myCircularQueue.deQueue();  // return True
 * myCircularQueue.enQueue(4); // return True
 * myCircularQueue.Rear();     // return 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= 1000
 * 0 <= value <= 1000
 * At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty,
 * and isFull.
 *
 *
 */

// @lc code=start

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int size;
    int head;
    int count;
    int *queue;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    int *queue = malloc(k * sizeof(*queue));

    MyCircularQueue *obj = malloc(sizeof(*obj));
    obj->head = 0;
    obj->count = 0;
    obj->size = k;
    obj->queue = queue;

    return obj;
}

inline bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->count == 0);
}

inline bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->count == obj->size);
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }

    obj->queue[(obj->head + obj->count) % obj->size] = value;
    ++obj->count;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }

    obj->head = (obj->head + 1) % obj->size;
    --obj->count;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }

    return obj->queue[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }

    int tail = (obj->head + obj->count - 1) % obj->size;
    return obj->queue[tail];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
// @lc code=end

