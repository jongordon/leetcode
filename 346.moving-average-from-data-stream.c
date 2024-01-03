/** Premium exercise so not in VSCode plugin **/

/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.


Example 1:

Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3


Constraints:

1 <= size <= 1000
-105 <= val <= 105
At most 104 calls will be made to next.
*/

#include <stdlib.h>

typedef struct {
    int *queue;
    int head;
    int count;
    int size;
} MovingAverage;


MovingAverage* movingAverageCreate(int size) {
    int *queue = malloc(size * sizeof(*queue));

    MovingAverage *obj = malloc(sizeof(*obj));
    obj->head = 0;
    obj->count = 0;
    obj->size = size;
    obj->queue = queue;

    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
    /* Add value to queue and increment count until it reaches queue size (will circle) */
    obj->queue[(obj->head + obj->count) % obj->size] = val;
    ++obj->count;

    /* Average the current count of values */
    int count = obj->count <= obj->size ? obj->count : obj->size;
    double sum = 0.0;

    for (int i = 0; i < count; ++i) {
        int tail = (obj->head + obj->count - 1 - i) % obj->size;
        sum += obj->queue[tail];
    }

    return (sum / count);
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);

 * movingAverageFree(obj);
*/