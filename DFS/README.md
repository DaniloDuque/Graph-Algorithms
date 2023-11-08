# Depth-First Search (DFS) Algorithm

## Overview

Depth-First Search (DFS) is a fundamental graph traversal algorithm used to explore all the vertices and edges of a graph in depth-first order. Unlike Breadth-First Search (BFS), DFS explores as far as possible along each branch before backtracking. DFS can be implemented using recursion or an explicit stack data structure and is a key component in many graph-related problems and algorithms.

## How DFS Works

1. **Initialization:** Start with the source node. Mark it as visited and explore its unvisited neighbors.

2. **Recursion or Stack:** In the recursive approach, for each unvisited neighbor of the current node, recursively apply DFS. In the stack-based approach, push the source node onto the stack. While the stack is not empty, pop a node, process it (e.g., print its value), mark it as visited, and push its unvisited neighbors onto the stack.

3. **Backtracking:** If a node has no unvisited neighbors, backtrack to the previous node and continue exploring other branches.

4. **Termination:** DFS continues until all nodes are visited, or until a specific node is found (e.g., in pathfinding problems).

## Time Complexity

The time complexity of DFS is **O(V + E)**, where **V** is the number of vertices (nodes) and **E** is the number of edges in the graph. Here's why:

- **Vertex Visits:** DFS visits every vertex exactly once, which takes **O(V)** time.

- **Edge Visits:** In the worst case, every edge is visited once to explore its adjacent nodes. This takes **O(E)** time.

Combining both aspects, the overall time complexity of DFS is **O(V + E)**.

## When to Use DFS Algorithm

DFS is particularly useful when:

- **Exploration of Entire Graph:** You need to explore all nodes and edges of a graph systematically.

- **Topological Sorting:** You want to find a linear ordering of the nodes in a directed acyclic graph (DAG).

- **Connected Components:** You need to find connected components in an undirected graph.

- **Cycle Detection:** You want to detect cycles in a graph.

DFS is also commonly used in various algorithms and data structures, such as solving mazes, finding paths, and traversing tree structures. Its versatility and simplicity make it a powerful tool for graph-related problems.
