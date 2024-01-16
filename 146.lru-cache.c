/*
 * @lc app=leetcode id=146 lang=c
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (41.89%)
 * Likes:    19822
 * Dislikes: 922
 * Total Accepted:    1.5M
 * Total Submissions: 3.6M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 *
 * Implement the LRUCache class:
 *
 *
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 *
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 *
 *
 */

// @lc code=start

#include <stdlib.h>

/* A doubly-linked list will naturally order the items as they are linked/unlinked */
struct Node {
    struct Node *next;
    struct Node *prev;
    int key;
    int value;
};

/* The LRUCache contains both the cache (as a basic lookup "hash map") and linked list mangement (queue) */
typedef struct {
    struct Node* *cache;
    struct Node *head;
    struct Node *tail;
    int count;
    int size;
} LRUCache;

void deleteNode(struct Node *node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
}

void addNode(struct Node *head, struct Node *node) {
    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj = malloc(sizeof(*obj));
    obj->cache = calloc(10001, sizeof(struct Node*));
    obj->size = capacity;
    obj->count = 0;

    /* Set an initial entry */
    obj->head = malloc(sizeof(struct Node));
    obj->tail = malloc(sizeof(struct Node));
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;

    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if (obj->count == 0 || obj->cache[key] == NULL) {
        return -1;
    }

    /* Simple "hash table" lookup by key directly */
    struct Node *node = obj->cache[key];

    /* Update linked list as node has been touched */
    deleteNode(node);
    addNode(obj->head, node);

    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    struct Node *node;

    /* Does this node already exist in the cache? */
    if (obj->cache[key]) {
        node = obj->cache[key];
        node->value = value;
        deleteNode(node);
        addNode(obj->head, node);
    }
    else {
        /* New node - will it fit? */
        if (obj->count == obj->size) {
            /* No. */
            --obj->count;
            obj->cache[obj->tail->prev->key] = NULL;
            deleteNode(obj->tail->prev);
        }

        /* Add it to the cache */
        ++obj->count;
        node = malloc(sizeof(*node));
        node->key = key;
        node->value = value;
        obj->cache[key] = node;
        addNode(obj->head, node);
    }
}

void lRUCacheFree(LRUCache* obj) {
    for (int i = 0; i < sizeof(obj->cache) / sizeof(obj->cache[0]); ++i) {
        if (obj->cache[i]) {
            free(obj->cache[i]);
        }
    }
    free(obj->cache);
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/
// @lc code=end

