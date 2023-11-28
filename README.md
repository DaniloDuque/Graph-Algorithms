# Graph Algorithms Repository

Welcome to my repository of graph algorithms implemented in C++ and Java. Whether you're an ICPC team member or a programming enthusiast, this collection is tailored to provide efficient and well-documented implementations of essential graph algorithms.

## Introduction to Graphs

Graphs, in the realm of discrete mathematics, are a fundamental data structure that consists of nodes (vertices) and edges connecting these nodes. The edges can be directed or undirected, and they represent relationships or connections between entities. Mathematically, a graph G is defined as a pair (V, E), where V is a set of vertices and E is a set of edges, each connecting a pair of vertices.

### Types of Graphs

- **Directed Graph (Digraph):** Edges have a direction.
- **Undirected Graph:** Edges are bidirectional.
- **Weighted Graph:** Edges have associated weights.
- **Bipartite Graph:** Vertices can be divided into two sets with edges only between sets.
- **Flow Graph:** A specialized directed graph where edges have capacities, representing the maximum amount of flow that can traverse the edge.

### Why Graphs in Computer Science?
Graphs model real-world relationships and dependencies, making them indispensable in various computer science applications. They are used in social network analysis, route planning, dependency resolution, and more.

## Algorithms

Explore our collection of graph algorithms, each implemented in both C++ and Java. The implementations are designed to be efficient for competitive programming environments in C++, providing clear and concise representations of the algorithms in Java.

### BFS (Breadth-First Search)
- Traverse the graph level by level.
- Explore all neighbors of a node before moving on.
- **Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges.

### Bellman-Ford
- Single-source shortest path algorithm.
- Handles graphs with negative edge weights.
- **Time Complexity:** O(V * E), where V is the number of vertices and E is the number of edges.

### Bipartite Graph Coloring
- Determines if a graph is bipartite.
- Vertices can be divided into two sets with no adjacent vertices in the same set.
- **Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges.

### DFS (Depth-First Search)
- Explores a graph by going as deep as possible before backtracking.
- Commonly used for topological sorting and finding connected components.
- **Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges.

### Dijkstra
- Finds the shortest path from a source node to all other nodes in a weighted graph.
- **Time Complexity:** O((V + E) * log V), where V is the number of vertices and E is the number of edges.

### Edmonds-Karp
- Solves the maximum flow problem in a flow network using the Ford-Fulkerson algorithm.
- **Time Complexity:** O(VE^2), where V is the number of vertices and E is the number of edges.

### Floyd-Warshall
- Finds the shortest paths between all pairs of vertices in a weighted graph.
- **Time Complexity:** O(V^3), where V is the number of vertices.

### Ford-Fulkerson
- Generic algorithm for finding the maximum flow in a flow network.
- **Time Complexity:** O(E * max_flow), where E is the number of edges.

### Gale-Shapley
- Solves the stable marriage problem, finding a stable matching between two sets of elements.
- **Time Complexity:** O(m^2 * n), where m is the number of elements on one side and n is the number on the other.

### Hierholzer
- Finds an Eulerian cycle in a graph, visiting each edge exactly once.
- **Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges.

### Johnson
- Finds all-pairs shortest paths in a graph, even with negative edge weights.
- **Time Complexity:** O(V^2 * log V + VE), where V is the number of vertices and E is the number of edges.

### Kruskal
- Finds a minimum spanning tree for a connected, undirected graph.
- **Time Complexity:** O(E * log V), where V is the number of vertices and E is the number of edges.

### Prim
- Finds a minimum spanning tree, growing it one edge at a time from an arbitrary node.
- **Time Complexity:** O((V + E) * log V), where V is the number of vertices and E is the number of edges.

### Tarjan
- Efficiently finds strongly connected components in a directed graph.
- **Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges.

### Topological Sort
- Orders the vertices of a directed acyclic graph (DAG) linearly based on dependencies.
- **Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges.

### Kahn's Algorithm
- Another method for topological sorting, using a queue to iteratively select nodes with no incoming edges.
- **Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges.

### Union Find
- Efficient data structure for tracking disjoint sets of elements.
- Determines whether two elements belong to the same set.
- **Time Complexity:** O(alpha(V)), where alpha(V) is the inverse Ackermann function and grows extremely slowly.

## Usage

Feel free to explore each algorithm's implementation within the repository to enhance your understanding and problem-solving skills. If you have any questions or suggestions, don´t hesitate to contribute, let's make this repository a comprehensive reference for ICPC teams and programmers alike. Happy coding! 🚀


