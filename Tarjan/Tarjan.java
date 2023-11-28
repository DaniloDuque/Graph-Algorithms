//This algorithm find the number of strongly conected components in a graph, but can be modified to find bridges and articulation points
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Tarjan {

    static BitSet onStack = new BitSet(100001);
    static ArrayList<ArrayList<Integer>> graph;
    static ArrayList<Integer> ids, low;
    static Stack<Integer> st;






  
    // Depth-First Search (DFS) function
    static void dfs(int start, int[] numSCC) {
        // Push the current vertex onto the stack
        st.push(start);
        // Mark the current vertex as on the stack
        onStack.set(start);
        // Initialize ids and low values for the current vertex
        ids.set(start, start);
        low.set(start, start);

        // Iterate through neighbors of the current vertex
        for (int neigh : graph.get(start)) {
            // If the neighbor has not been visited, recursively call dfs
            if (ids.get(neigh) == -1) {
                dfs(neigh, numSCC);
            }
            // If the neighbor is on the stack, update low value of the current vertex
            if (onStack.get(neigh)) {
                low.set(start, Math.min(low.get(start), low.get(neigh)));
            }
        }

        // Check if the current vertex is the root of a strongly connected component (SCC)
        if (ids.get(start) == low.get(start)) {
            // Pop vertices from the stack until the current vertex is encountered
            while (!st.isEmpty()) {
                int curr = st.pop();
                // Mark the vertex as not on the stack
                onStack.clear(curr);
                // Update low value of the popped vertex
                low.set(curr, ids.get(start));
                // Break the loop if the root of the SCC is encountered
                if (curr == start) {
                    break;
                }
            }
            // Increment the number of SCCs
            numSCC[0]++;
        }
    }









  

    // Tarjan's Algorithm for finding strongly connected components
    static int tarjan(ArrayList<ArrayList<Integer>> graph) {
        int[] numSCC = {0};
        // Initialize arrays for storing ids and low values
        ids = new ArrayList<>(Collections.nCopies(graph.size(), -1));
        low = new ArrayList<>(Collections.nCopies(graph.size(), 0));

        // Iterate through each vertex in the graph
        for (int i = 0; i < graph.size(); ++i) {
            // If the vertex has not been visited, perform DFS
            if (ids.get(i) == -1) {
                dfs(i, numSCC);
            }
        }

        // Return the number of strongly connected components in the graph
        return numSCC[0];
    }





  

    public static void main(String[] args) throws IOException {
        // Input reading using BufferedReader
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n, m, node1, node2;
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        n = Integer.parseInt(tokenizer.nextToken());
        m = Integer.parseInt(tokenizer.nextToken());

        // Initialize the graph as an ArrayList of ArrayLists
        graph = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        // Initialize stack for DFS
        st = new Stack<>();

        // Read edges and populate the graph
        for (int i = 0; i < m; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            node1 = Integer.parseInt(tokenizer.nextToken());
            node2 = Integer.parseInt(tokenizer.nextToken());
            graph.get(node1).add(node2);
        }

        // Output the number of strongly connected components in the graph
        System.out.println(tarjan(graph));
    }
}
