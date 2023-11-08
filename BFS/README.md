# Breadth-First Search (BFS) Algorithm

## Overview

Breadth-First Search (BFS) is a graph traversal algorithm used to explore all the vertices and edges of a graph in breadth-first order. Unlike depth-first search, which explores as far as possible along each branch before backtracking, BFS explores the graph level by level. It starts at the source node and explores all its neighbors at the present depth before moving on to nodes at the next level of depth. BFS is often used for finding the shortest path in an unweighted graph, determining connected components, and solving puzzles with multiple solutions.

## How BFS Works

1. **Initialization:** Start with the source node. Mark it as visited and enqueue it in a queue.

2. **Exploration:** While the queue is not empty, dequeue a node, process it (e.g., print its value), and enqueue all its unvisited neighbors. Mark each visited node to avoid revisiting.

3. **Level-By-Level Exploration:** BFS explores the graph in layers. It first explores all neighbors of the source node, then moves on to their neighbors, and so on. This ensures that nodes closer to the source are visited before nodes farther away.

4. **Termination:** BFS continues until the queue is empty, meaning all reachable nodes have been visited.

## Time Complexity

The time complexity of BFS is **O(V + E)**, where **V** is the number of vertices (nodes) and **E** is the number of edges in the graph. Here's why:

- **Vertex Visits:** BFS visits every vertex exactly once, which takes **O(V)** time.

- **Edge Visits:** In the worst case, every edge is visited once to explore its adjacent nodes. This takes **O(E)** time.

Combining both aspects, the overall time complexity of BFS is **O(V + E)**, making it efficient for exploring graphs, especially when the graph is represented using an adjacency list.

BFS is particularly useful when finding the shortest path between two nodes in an unweighted graph or when systematically exploring a graph level by level. Its time complexity makes it suitable for analyzing large graphs efficiently.
