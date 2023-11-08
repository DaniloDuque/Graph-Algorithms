# Kruskal's Algorithm

## Overview

Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph. A minimum spanning tree is a subset of the edges of the graph that connects all the vertices together without any cycles and with the minimum possible total edge weight. Kruskal's algorithm builds the MST by adding edges to the tree in ascending order of their weights until all vertices are connected.

## How Kruskal's Algorithm Works

1. **Initialization:** Create a forest where each vertex is a separate tree.

2. **Sort Edges:** Sort all the edges in the graph in non-decreasing order of their weights.

3. **Iterative Edge Selection:** Iterate through the sorted edges. For each edge, if it does not form a cycle with the edges already in the MST, add it to the MST. Checking for cycles can be efficiently done using disjoint-set data structures (such as Union-Find).

4. **Termination:** Continue this process until there are V - 1 edges in the MST, where V is the number of vertices in the graph.

## Time Complexity

The time complexity of Kruskal's algorithm is **O(E log E)**, where **E** is the number of edges in the graph. Here's why:

- **Sorting Edges:** Sorting all the edges takes **O(E log E)** time.

- **Iterating Through Edges:** Iterating through the sorted edges and performing disjoint-set operations takes **O(E log* V)** time, where log* V is the iterated logarithm of the number of vertices. In practice, this can be considered nearly linear and is dominated by the edge sorting step.

Combining both aspects, the overall time complexity is **O(E log E)**.

## When to Use Kruskal's Algorithm

Kruskal's algorithm is suitable when:

- **Sparse Graphs:** The graph is sparse, meaning it has relatively few edges compared to the number of vertices.

- **Edge Weights:** The graph edges have arbitrary or non-negative weights.

- **Finding Minimum Spanning Tree:** You want to find the minimum spanning tree of the graph.

Kruskal's algorithm is commonly used in network design, circuit design, and clustering algorithms where finding the minimum connection cost is essential. It is particularly efficient for sparse graphs with a large number of vertices.
