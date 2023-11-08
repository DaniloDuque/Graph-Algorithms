# Floyd-Warshall Algorithm

## Overview

The Floyd-Warshall algorithm is a dynamic programming algorithm used to find the shortest paths between all pairs of nodes in a weighted graph, including negative-weight edges. It was proposed independently by Robert Floyd and Stephen Warshall in the 1960s. Unlike Dijkstra's algorithm, which finds the shortest path from one source node to all other nodes, the Floyd-Warshall algorithm computes the shortest paths between all pairs of nodes in a graph.

## How it Works

The algorithm works by iteratively updating the shortest path distances between all pairs of nodes. It maintains a 2D array, often called the "distance matrix," where each element `dist[i][j]` represents the shortest distance from node `i` to node `j`. The algorithm considers all intermediate nodes and checks if using an intermediate node results in a shorter path between any pair of nodes. The process continues until the shortest paths between all pairs of nodes are calculated.

## When to Use the Floyd-Warshall Algorithm

Floyd-Warshall algorithm is useful when:

1. **All-Pairs Shortest Path Problem:** You need to find the shortest paths between all pairs of nodes in a graph.

2. **Negative-Weight Edges:** The graph may contain negative-weight edges, and you want to find the shortest paths in the presence of negative weights.

3. **No Negative Cycles:** There are no negative cycles in the graph. The algorithm does not work correctly if the graph contains negative cycles.


## Time Complexity:


Triple Nested Loops: The algorithm uses three nested loops, iterating over all pairs of nodes (V^2) and considering all possible intermediate nodes (V). Therefore, the time complexity of the main part of the algorithm is O(V^3).

