/*
 * @lc app=leetcode id=133 lang=c
 *
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph/description/
 *
 * algorithms
 * Medium (55.59%)
 * Likes:    9080
 * Dislikes: 3627
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '[[2,4],[1,3],[2,4],[1,3]]'
 *
 * Given a reference of a node in a connected undirected graph.
 *
 * Return a deep copy (clone) of the graph.
 *
 * Each node in the graph contains a value (int) and a list (List[Node]) of its
 * neighbors.
 *
 *
 * class Node {
 * ⁠   public int val;
 * ⁠   public List<Node> neighbors;
 * }
 *
 *
 *
 *
 * Test case format:
 *
 * For simplicity, each node's value is the same as the node's index
 * (1-indexed). For example, the first node with val == 1, the second node with
 * val == 2, and so on. The graph is represented in the test case using an
 * adjacency list.
 *
 * An adjacency list is a collection of unordered lists used to represent a
 * finite graph. Each list describes the set of neighbors of a node in the
 * graph.
 *
 * The given node will always be the first node with val = 1. You must return
 * the copy of the given node as a reference to the cloned graph.
 *
 *
 * Example 1:
 *
 *
 * Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
 * Output: [[2,4],[1,3],[2,4],[1,3]]
 * Explanation: There are 4 nodes in the graph.
 * 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val =
 * 4).
 * 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val =
 * 3).
 * 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val =
 * 4).
 * 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val =
 * 3).
 *
 *
 * Example 2:
 *
 *
 * Input: adjList = [[]]
 * Output: [[]]
 * Explanation: Note that the input contains one empty list. The graph consists
 * of only one node with val = 1 and it does not have any neighbors.
 *
 *
 * Example 3:
 *
 *
 * Input: adjList = []
 * Output: []
 * Explanation: This an empty graph, it does not have any nodes.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the graph is in the range [0, 100].
 * 1 <= Node.val <= 100
 * Node.val is unique for each node.
 * There are no repeated edges and no self-loops in the graph.
 * The Graph is connected and all nodes can be visited starting from the given
 * node.
 *
 *
 */

// @lc code=start

#include <stdlib.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node* dfs(struct Node *node, struct Node* *visited) {
    /* Have we cloned this node before already? */
    if (visited[node->val]) {
        if (visited[node->val]->val == node->val) {
            return visited[node->val];
        }
    }

    /* Clone the node and add it to visited at the index or original node's value */
    struct Node *clone = calloc(1, sizeof(*clone));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = calloc(clone->numNeighbors, sizeof(struct Node *));
    visited[node->val] = clone;

    /* Now iterate through neighbors, recursively navigating them too */
    for (int i = 0; i < node->numNeighbors; ++i) {
        clone->neighbors[i] = dfs(node->neighbors[i], visited);
    }

    return clone;
}

struct Node *cloneGraph(struct Node *s) {
	if (s == NULL) {
        return NULL;
    }

    /* Like a hashmap but we use index directly (will only be 100 nodes max) */
    struct Node* *visited = calloc(101, sizeof(struct Node *));

    /* Perform a DFS, start at given node */
    return dfs(s, visited);
}
// @lc code=end

