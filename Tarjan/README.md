# Tarjan's Algorithm for Strongly Connected Components (SCCs), Articulation Points, and Bridges

## Overview

Tarjan's algorithm is a depth-first search-based algorithm used to find the strongly connected components (SCCs) of a directed graph. SCCs are subsets of vertices where every vertex in the subset is reachable from every other vertex. Tarjan's algorithm efficiently identifies these components and assigns a unique identifier to each SCC. Additionally, it can be extended to find articulation points and bridges in an undirected graph.

## How Tarjan's Algorithm Works

1. **Depth-First Search (DFS):** Perform a depth-first search traversal of the graph. During the traversal, maintain information about the visited vertices, their discovery times, low-link values, and whether they are currently on the stack.

2. **Stack-Based Tracking:** Use a stack to keep track of the vertices visited during the DFS traversal. When a vertex is discovered, it is pushed onto the stack. When an SCC is found, vertices are popped from the stack until the current vertex is reached, forming the SCC.

3. **Identifying SCCs:** During the DFS traversal, as vertices are popped from the stack, identify and output SCCs based on low-link values. A vertex belongs to an SCC if its low-link value is equal to its discovery time.

4. **Finding Articulation Points and Bridges (Optional):** By tracking the discovery times and low-link values during the DFS traversal, Tarjan's algorithm can identify articulation points and bridges in an undirected graph.

## Time Complexity

The time complexity of Tarjan's algorithm is **O(V + E)**, where **V** is the number of vertices and **E** is the number of edges in the graph. Here's why:

- **DFS Traversal:** Performing a depth-first search takes **O(V + E)** time to visit all vertices and edges.

- **Stack Operations:** Pushing and popping vertices onto/from the stack takes constant time, **O(1)**, since the stack operations do not depend on the number of vertices.

Combining both aspects, the overall time complexity is **O(V + E)**.

## When to Use Tarjan's Algorithm

Tarjan's algorithm is suitable when:

- **Directed Graph:** You are dealing with a directed graph (digraph) where the edges have a specific direction.

- **Finding SCCs:** You want to find the strongly connected components of the graph.

- **Finding Articulation Points and Bridges:** You need to find articulation points and bridges in an undirected graph. Tarjan's algorithm can be extended to solve this problem efficiently.

- **Efficiency:** You need an efficient algorithm with linear time complexity for both vertices and edges.

