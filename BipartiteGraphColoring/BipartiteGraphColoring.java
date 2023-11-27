import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BipartiteGraphColoring{

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }



    static class Graph {

        List<List<Integer>> adjList;

        Graph(int size) {
            adjList = new ArrayList<>(size);
            for (int i = 0; i < size; i++) {
                adjList.add(new ArrayList<>());
            }
        }

        void addEdge(int src, int dest) {
            adjList.get(src).add(dest);
        }

    }




    static boolean isBipartite(Graph graph, int i) {

        int[] memo = new int[100000];
        Arrays.fill(memo, 0);


        memo[i] = 1;
        Queue<Integer> bfs = new LinkedList<>();
        bfs.add(i);
        

        while (!bfs.isEmpty()) {
            int curr = bfs.poll();

            for (int neigh : graph.adjList.get(curr)) {
                if (memo[neigh] == memo[curr]) {
                    return false;
                }

                if (memo[neigh] == 0) {
                    bfs.add(neigh);
                    memo[neigh] = ~memo[curr];
                }
            }
        }return true;
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
            graph.addEdge(node1, node2);
            graph.addEdge(node2, node1);
        }
        System.out.println(isBipartite(graph, 0));
    }
}
