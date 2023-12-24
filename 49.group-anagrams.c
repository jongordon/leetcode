/*
 * @lc app=leetcode id=49 lang=c
 *
 * [49] Group Anagrams
 */

// @lc code=start

#include <stdlib.h>
#include <string.h>

struct hash {
    int index;
    char* value;
};

int compare_letters(void const* a, void const* b) {
    char _a = *(char *)a;
    char _b = *(char *)b;

    if (_a < _b) { return -1; }
    if (_a > _b) { return 1; }
    return 0;
}

int compare_words(void const* a, void const* b) {
    char* _a = ((struct hash *)a)->value;
    char* _b = ((struct hash *)b)->value;

    return strcmp(_a, _b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    /* Finding anagrams is as easy as sorting the array lexicographically and then finding duplicates */

    /* Start with the edge case for one string */
    if (strsSize == 1) {
        char*** res = malloc(sizeof(char*));
        *returnColumnSizes = malloc(sizeof(int*));
        res[0] = malloc(sizeof(char*));
        res[0][0] = strs[0];
        (*returnColumnSizes)[0] = 1;
        *returnSize = 1;
        return res;
    }

    /* Track original indices before being sorted */
    struct hash* map = malloc(strsSize * sizeof(struct hash));
    for (int i = 0; i < strsSize; ++i) {
        map[i].index = i;
        map[i].value = strdup(strs[i]);
    }

    /* Sort each individual string first */
    for (int i = 0; i < strsSize; ++i) {
        qsort(map[i].value, strlen(map[i].value), sizeof(char), compare_letters);
    }

    /* Now sort all the strings together */
    qsort(map, strsSize, sizeof(struct hash), compare_words);

    /* Prepare results */
    *returnColumnSizes = malloc(strsSize * sizeof(int*));
    char*** res = malloc(strsSize * sizeof(char*));

    /* Finally, iterate through all the strings, grouping together duplicates */
    int group = 0;
    for (int i = 0; i < strsSize; ++i, ++group) {
        /* Allocate worst-case space */
        res[group] = malloc(strsSize * sizeof(char*));
        int count = 0;

        /* Add original string from tracked index and any others that match */
        res[group][count] = strs[map[i].index];
        if (i < strsSize - 1) {
            while (strcmp(map[i].value, map[i + 1].value) == 0) {
                ++count;
                res[group][count] = strs[map[i + 1].index];
                ++i;
                if (i >= strsSize - 1) { break; }
            }
        }

        /* Finished group, update this group count returned */
        (*returnColumnSizes)[group] = count + 1;
    }

    /* returnsize is number of groups created */
    *returnSize = group;

    return res;
}
// @lc code=end

