# Ford-Fulkerson Algorithm for Maximum Flow

## Overview

The Ford-Fulkerson Algorithm is a powerful method used to find the maximum flow in a flow network. It aims to determine the optimal way to transport goods or information through a network, maximizing the flow from a source node to a sink node. The algorithm iteratively augments the flow along paths in the residual graph until no augmenting paths exist. The final flow represents the maximum possible flow in the network.

## Input and Output Representation

In the algorithm, the input is typically represented as a flow network, comprising a directed graph with capacities assigned to edges.

The output of the algorithm is the maximum flow value and the corresponding flow through each edge in the network.

## How Ford-Fulkerson Algorithm Works

1. **Initialization:** Start with an initial feasible flow, often set to zero.

2. **Augmenting Paths:** Find augmenting paths in the residual graph (the graph with remaining capacity in each edge). This is commonly done using Breadth-First Search (BFS) or Depth-First Search (DFS).

3. **Flow Augmentation:** Augment the flow along the found paths, updating the residual capacities.

4. **Termination:** Repeat steps 2 and 3 until no more augmenting paths can be found.

5. **Maximum Flow Calculation:** The maximum flow is the sum of all flow values into the sink node.

## When to Use Ford-Fulkerson Algorithm

The Ford-Fulkerson Algorithm is suitable when:

- **Maximum Flow Problem:** There is a need to find the maximum flow in a flow network.

- **Directed Graph:** The network is represented as a directed graph with assigned capacities on each edge.

- **Feasible Initial Flow:** An initial feasible flow needs to be provided, often set to zero.

