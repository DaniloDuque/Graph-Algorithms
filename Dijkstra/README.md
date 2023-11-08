# Dijkstra's Algorithm

## Overview

Dijkstra's algorithm is a fundamental graph search algorithm that finds the shortest path between nodes in a weighted graph, which may represent, for example, road networks. It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later. The algorithm is widely used in various applications, such as routing, network analysis, and GPS navigation systems, where finding the most efficient path is crucial.

## How it Works

Dijkstra's algorithm works by iteratively expanding the shortest path from the source node to all other nodes in the graph. It maintains a set of nodes whose shortest distance from the source node is known. At each step, the algorithm selects the node with the smallest known distance, explores all its neighbors, and updates their distances if a shorter path is found. This process continues until the algorithm has visited all nodes in the graph.

## When to Use Dijkstra's Algorithm

Dijkstra's algorithm is particularly useful when:

1. **Single-Source Shortest Path Problem:** You need to find the shortest path from a single source node to all other nodes in the graph.

2. **Non-Negative Edge Weights:** The graph contains non-negative edge weights. Dijkstra's algorithm does not work with negative edge weights, as it assumes that a shorter path will not be found once a node's shortest distance is finalized.


## Time Complexity with Min-Heap: O((V + E) * log(V))

    V: Number of vertices (nodes) in the graph.
    E: Number of edges in the graph.

Here's the breakdown of the time complexity:

    Inserting all nodes into the min-heap: O(V * log(V)) - Inserting V nodes into a binary heap takes O(V * log(V)) time.

    Extracting the minimum node V times: O(V * log(V)) - Extracting the minimum element from the min-heap V times, where V is the number of vertices.

    Decreasing key (distance) operation: O(E * log(V)) - In the worst case, every edge needs to be relaxed (distance updated) E times. Decreasing a key in a binary heap takes O(log(V)) time. Since there are E edges, the total time spent on the decrease key operation is O(E * log(V)).

Combining these steps, the overall time complexity of Dijkstra's algorithm with a min-heap is O((V + E) * log(V)). Using the min-heap data structure efficiently keeps track of the minimum distance node, reducing the time complexity compared to simpler implementations that involve linear searches for finding the minimum node.
