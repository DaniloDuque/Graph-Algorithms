# Kahn's Algorithm for Topological Sorting (Including Cycle Detection)

## Overview

Kahn's Algorithm is a method used to perform topological sorting on a directed acyclic graph (DAG). Topological sorting of a graph is a linear ordering of its vertices such that for every directed edge \(u \rightarrow v\), vertex \(u\) comes before \(v\) in the ordering. Kahn's Algorithm specifically works for DAGs, where no cycles exist, making it an essential tool in various applications, including task scheduling, dependency resolution, and job sequencing. Additionally, Kahn's Algorithm can detect cycles in the input graph, and in case of a cycle, it returns a null vector.

## Input and Output Representation

In the algorithm, the input is represented as an adjacency list or matrix, describing the connections between vertices in the graph.

The output of the algorithm is either a linear ordering of the vertices, representing a topological sort of the graph, or a null vector if a cycle is detected.

## How Kahn's Algorithm Works

1. **Initialization:** Compute the in-degree (number of incoming edges) for each vertex in the graph.

2. **Queue-Based Approach:** Start with vertices having in-degree 0. Enqueue these vertices into a queue.

3. **Processing:** While the queue is not empty, dequeue a vertex, and for each of its adjacent vertices, reduce their in-degree by 1. If any of these vertices have an in-degree of 0 after reduction, enqueue them.

4. **Cycle Detection:** If the queue becomes empty but not all vertices are processed, it indicates the presence of a cycle in the graph. In this case, the algorithm returns a null vector.

5. **Termination:** Continue this process until the queue is empty. The vertices are dequeued in topological order, forming the output, or a null vector is returned in case of a cycle.

## When to Use Kahn's Algorithm

Kahn's Algorithm for topological sorting is suitable when:

- **Directed Acyclic Graph (DAG):** The graph is directed and acyclic, meaning it has no cycles.

- **Topological Order:** There is a need to find a valid topological ordering of the vertices.

- **Dependency Resolution:** Tasks or activities have dependencies, and the goal is to schedule them in a way that satisfies these dependencies.

- **Cycle Detection:** The algorithm can also be used to detect cycles in the graph. If a cycle is detected, it returns a null vector, indicating the presence of a cycle.

- **Efficiency:** An efficient algorithm with linear time complexity for both vertices and edges is required.

