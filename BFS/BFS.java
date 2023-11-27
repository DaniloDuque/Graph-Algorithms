import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BFS {

    // Declaration of global variables
    static BitSet vis = new BitSet(100001);
    static Queue<Integer> bfs = new ArrayDeque<>();

    // Definition of a data type to represent a graph as an adjacency list
    static class Graph {

        Vector<Vector<Integer>> adjList;

        Graph(int size) {
            adjList = new Vector<>(size);
            for (int i = 0; i < size; i++) {
                adjList.add(new Vector<>());
            }
        }

        void addEdge(int src, int dest) {
            adjList.get(src).add(dest);
            // adjList.get(dest).add(src);  //in case of an undirected graph
        }
    }



  

    // Implementation of the breadth-first search algorithm (BFS)
    static void BFS(Graph graph, int start) {

        System.out.print(start + " ");
        bfs.add(start);
        vis.set(start);

        while (!bfs.isEmpty()) {
            int curr = bfs.poll();

            for (int neigh : graph.adjList.get(curr)) {
                if (!vis.get(neigh)) {  // if neigh is not visited
                    System.out.print(neigh + " ");
                    bfs.add(neigh);    // add it to the queue
                    vis.set(neigh);    // mark as visited
                }
            }
        }
        System.out.println();
    }





  
    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int N, M, Start, x, y;

        // Input data
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        N = Integer.parseInt(tokenizer.nextToken());  // Number of vertices
        M = Integer.parseInt(tokenizer.nextToken());  // Number of edges
        Start = Integer.parseInt(tokenizer.nextToken());  // Start vertex

        // Create the graph
        Graph graph = new Graph(N);

        // Input the edges and build the graph
        for (int i = 0; i < M; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            x = Integer.parseInt(tokenizer.nextToken());
            y = Integer.parseInt(tokenizer.nextToken());
            graph.addEdge(x, y);
        }

        // Call the BFS function
        BFS(graph, Start);
    }
}




