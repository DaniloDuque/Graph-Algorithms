import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;





public class BellmanFord {




    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }






    static class Graph {

        List<List<Pair>> adjList;

        Graph(int size) {
            adjList = new ArrayList<>(size);
            for (int i = 0; i < size; i++) {
                adjList.add(new ArrayList<>());
            }
        }

        void addEdge(int src, int dest, int weight) {
            adjList.get(src).add(new Pair(dest, weight));
        }


    }






    static List<Integer> infiniteCycles(Graph graph, List<Integer> minRoutes) {

        for (int i = 0; i < graph.adjList.size() - 1; ++i)
            for (int u = 0; u < graph.adjList.size(); ++u)
                for (Pair edge : graph.adjList.get(u))
                    if (minRoutes.get(edge.first) > minRoutes.get(u) + edge.second)   //if a value is updated, then a negative cycle is detected
                        minRoutes.set(edge.first, Integer.MIN_VALUE);                 // Use Integer.MIN_VALUE for negative infinity

        return minRoutes;

    }



    static List<Integer> bellmanFord(Graph graph, int start) {

        List<Integer> minRoutes = new ArrayList<>(Collections.nCopies(graph.adjList.size(), Integer.MAX_VALUE));
        minRoutes.set(start, 0);
        for (int i = 0; i < graph.adjList.size() - 1; ++i)
            for (int u = 0; u < graph.adjList.size(); ++u)
                for (Pair edge : graph.adjList.get(u))
                    if (minRoutes.get(edge.first) > minRoutes.get(u) + edge.second)
                        minRoutes.set(edge.first, minRoutes.get(u) + edge.second);

        return infiniteCycles(graph, minRoutes);

    }









    public static void main(String[] args) throws IOException {


        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());


        Graph graph = new Graph(n);

        for (int i = 0; i < m; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int node1 = Integer.parseInt(tokenizer.nextToken());
            int node2 = Integer.parseInt(tokenizer.nextToken());
            int weight = Integer.parseInt(tokenizer.nextToken());
            graph.addEdge(node1, node2, weight);
        }

        List<Integer> bell = bellmanFord(graph, 0);
        for (int i : bell)
            System.out.print(i + " ");
        System.out.println();


    }
}




