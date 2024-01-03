/** Premium exercise so not in VSCode plugin **/

/*
You are given an m x n grid rooms initialized with these three possible values.

-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.



Example 1:


Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
Example 2:

Input: rooms = [[-1]]
Output: [[-1]]


Constraints:

m == rooms.length
n == rooms[i].length
1 <= m, n <= 250
rooms[i][j] is -1, 0, or 231 - 1.
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(int x, int y, int m, int n, int** rooms) {
    return x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] == INT32_MAX;
}

void wallsAndGates(int** rooms, int roomsSize, int* roomsColSize) {
    int m = roomsSize;
    int n = roomsColSize[0];

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int queueSize = m * n * 2;  /* Multiply by two as we store pairs of x,y co-ords */
    int *queue = malloc(queueSize * sizeof(*queue));
    int head = 0, tail = 0;


    /* Find all the gates first, and add them to the queue (as pair of co-ords) to be checked */
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (rooms[i][j] == 0) {
                queue[tail++] = i;
                queue[tail++] = j;
            }
        }
    }

    /* Navigate the queue */
    while (head < tail) {
        int x = queue[head++];
        int y = queue[head++];

        /* Check every direction around this co-ord */
        for (int i = 0; i < 4; ++i) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            if (isValid(newX, newY, m, n, rooms)) {
                rooms[newX][newY] = rooms[x][y] + 1;    /* One step further than before */
                /* Add co-ords to queue to check later */
                queue[tail++] = newX;
                queue[tail++] = newY;
            }
        }
    }

    free(queue);
}