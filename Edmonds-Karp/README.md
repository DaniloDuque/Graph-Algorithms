# Edmonds-Karp Algorithm for Maximum Flow

## Overview

The Edmonds-Karp Algorithm is an implementation of the Ford-Fulkerson method for computing maximum flow in a flow network. It leverages Breadth-First Search (BFS) to efficiently find augmenting paths in the residual graph.

## How Edmonds-Karp Algorithm Works  

1. **Initialization:** Start with zero flow and compute the residual capacity for each edge.

2. **Breadth-First Search:** Use BFS in the residual graph to find an augmenting path from source to sink.

3. **Flow Augmentation:** Augment flow along the path found, update residual capacities.

4. **Repeat:** Repeat steps 2 and 3 until no augmenting path exists.

5. **Maximum Flow:** Sum all flow values entering the sink node.

## Advantages over Ford-Fulkerson

- Runs faster by using BFS instead of DFS.

- Provides better runtime complexity O(VE^2).

- Allows finding maximum flow more efficiently.

## When to Use Edmonds-Karp

The Edmonds-Karp algorithm is well-suited for:

- Finding maximum flow in networks with large capacity edges. 

- Sparse flow networks where |E| is much less than |V|^2.

- Applications where runtime performance is critical.
