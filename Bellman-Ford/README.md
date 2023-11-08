# Bellman-Ford Algorithm

## Overview

The Bellman-Ford algorithm is a versatile algorithm used to find the shortest paths from a source node to all other nodes in a weighted graph, even in the presence of negative-weight edges. It can also detect negative cycles in the graph. Named after mathematicians Richard Bellman and Lester Ford, this algorithm is essential for network routing protocols and various other applications in computer science and engineering.

## How Bellman-Ford Works

1. **Initialization:** Start by setting the distance from the source node to itself as 0, and distances to all other nodes as infinity. 

2. **Relaxation:** Iterate through all edges (V - 1) times, where V is the number of vertices. For each edge (u, v) with weight w, update the distance to node v as min(distance[v], distance[u] + w). This step ensures that the algorithm gradually improves the distance estimates for each node.

3. **Negative Cycle Detection:** After the V - 1 iterations, perform one more iteration. If any distance can be further reduced, then the graph contains a negative cycle.

## How Bellman-Ford Handles Negative Weights

Bellman-Ford works even in the presence of negative-weight edges, but it can't handle negative cycles. If there is a negative cycle reachable from the source node, the algorithm can detect it during the extra iteration step.

## Time Complexity

The time complexity of the Bellman-Ford algorithm is **O(V * E)**, where **V** is the number of vertices and **E** is the number of edges. Here's why:

- **V - 1 Iterations:** The algorithm relaxes all edges V - 1 times, taking **O(V * E)** time in total.

- **Extra Iteration:** To detect negative cycles, Bellman-Ford performs an additional iteration over all edges, taking **O(E)** time.

Combining both aspects, the overall time complexity is **O(V * E)**.

## When to Use Bellman-Ford Algorithm

Bellman-Ford should be used when:

- **Negative Weight Edges:** The graph contains negative-weight edges.
  
- **Single-Source Shortest Path:** You need to find the shortest paths from a single source node to all other nodes in the graph.

- **Negative Cycle Detection:** You want to detect negative cycles in the graph.

Bellman-Ford is not the most efficient algorithm, especially for large graphs, but it is a reliable choice when negative-weight edges are involved or when negative cycles need to be detected.
