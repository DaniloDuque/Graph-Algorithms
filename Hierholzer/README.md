# Hierholzer's Algorithm for Eulerian Paths

## Overview

Hierholzer's Algorithm is a powerful method used to find Eulerian paths in a directed or undirected graph. An Eulerian path is a path that traverses each edge of the graph exactly once, visiting every vertex, and can end at a different vertex than the starting one. Hierholzer's Algorithm is particularly valuable for graphs with certain degree characteristics. It efficiently reconstructs Eulerian paths, making it applicable in diverse fields such as network analysis, DNA sequencing, and logistics.

## Input and Output Representation

In the algorithm, the input is typically represented as an adjacency list or matrix, describing the connections between vertices in the graph.

The output of the algorithm is a sequence of vertices forming an Eulerian path. If the graph has no Eulerian path, the output is empty.

## How Hierholzer's Algorithm Works

1. **Initialization:** Start from an arbitrary vertex. If the graph is not connected, start the algorithm from a vertex in a connected component.

2. **Hierholzer's Observation:** Use a modified depth-first search to traverse edges while removing them from the graph. Backtrack only when there are no more edges to explore from the current vertex.

3. **Path Construction:** Build the Eulerian path by concatenating the vertices during the traversal.

4. **Termination:** The algorithm terminates when all edges are visited.

## When to Use Hierholzer's Algorithm for Eulerian Paths

Hierholzer's Algorithm for Eulerian Paths is suitable when:

- **Eulerian Path:** There is a need to find an Eulerian path in a graph.

- **Graph Properties:** The graph is connected (or the algorithm is applied to each connected component), and there are at most two vertices with odd degrees (endpoints of the Eulerian path).

- **Efficiency:** An efficient algorithm with linear time complexity for both vertices and edges is required.

