# Johnson's Algorithm for All Pairs Shortest Paths

## Overview

Johnson's Algorithm is a versatile method used to find the shortest paths between all pairs of vertices in a weighted directed graph. It can handle graphs with negative edge weights, making it suitable for a wide range of applications. The algorithm involves a transformation of the original graph, applying Bellman-Ford algorithm for each vertex to remove negative weights, and then using Dijkstra's algorithm for each vertex to find the shortest paths.

## Input and Output Representation

In the algorithm, the input is typically represented as a weighted directed graph, where the weights can be positive or negative.

The output of the algorithm is a matrix representing the shortest path distances between all pairs of vertices. If there are negative cycles in the graph, the algorithm may indicate that the problem is not well-defined.

## How Johnson's Algorithm Works

1. **Graph Transformation:** Add a new vertex connected to all existing vertices with zero-weight edges. Assign this new vertex a distance of zero.

2. **Bellman-Ford Algorithm:** Apply the Bellman-Ford algorithm to find the shortest distances from the new vertex to all other vertices, detecting and handling negative cycles if present.

3. **Graph Reweighting:** Adjust the edge weights using the computed distances to remove negative weights.

4. **Dijkstra's Algorithm:** Apply Dijkstra's algorithm for each vertex to find the shortest paths in the transformed graph.

5. **Revert Transformation:** Adjust the distances to account for the added vertex and revert the transformation.

## When to Use Johnson's Algorithm

Johnson's Algorithm is suitable when:

- **All Pairs Shortest Paths:** There is a need to find the shortest paths between all pairs of vertices in a graph.

- **Weighted Directed Graph:** The graph is represented as a weighted directed graph.

- **Negative Edge Weights:** The graph may have negative edge weights.

- **Efficiency:** The algorithm is more efficient than Floyd-Warshall for sparse graphs with non-negative edge weights.

