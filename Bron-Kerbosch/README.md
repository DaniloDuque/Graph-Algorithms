# Bron-Kerbosch Algorithm with Pivoting

## Overview

The Bron-Kerbosch algorithm is a well-known algorithm in graph theory used to find all cliques in an undirected graph. It was introduced by Coen Bron and Joep Kerbosch in 1973. The algorithm employs a backtracking approach to explore and enumerate all cliques in the graph efficiently. Pivoting is a technique often applied to improve the algorithm's performance by reducing redundant computations during the recursive exploration.

## How it Works

The Bron-Kerbosch algorithm with pivoting works by iteratively selecting a pivot vertex and exploring cliques containing that pivot. The algorithm maintains three sets of vertices: R (currently in the clique), P (candidates to be added to the clique), and X (excluded vertices). It then iteratively selects a pivot vertex, explores the neighbors of the pivot, and recursively calls itself with updated sets R, P, and X. The pivoting strategy optimizes the selection of the pivot, reducing the number of recursive calls.

## When to Use Bron-Kerbosch with Pivoting

The Bron-Kerbosch algorithm with pivoting is particularly useful when:

1. **Enumerating All Cliques:** You need to find all cliques in an undirected graph.

2. **Graph Exploration:** Efficiently exploring and enumerating cliques in large graphs.

## Time Complexity

The time complexity of the Bron-Kerbosch algorithm with pivoting is exponential and can be expressed as O(3^n), where n is the number of vertices in the graph. This notation reflects the worst-case scenario, where each recursive call can potentially explore three different branches (corresponding to the three sets R, P, and X). The application of pivoting helps reduce the overall number of recursive calls, mitigating some of the exponential complexity.

Please note that the actual performance may vary based on the characteristics of the input graph. In practice, the use of pivoting often results in significant improvements in performance compared to the basic Bron-Kerbosch algorithm.
