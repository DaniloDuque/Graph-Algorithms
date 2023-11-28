import java.util.ArrayList;
import java.util.List;



public class DisjointSet {


    private int size, numSets, numFrat = 0, numLoner = 0;
    private int[] set, rank, setSize;
    private List<List<Integer>> graph;
    

    // Helper method to swap the values of two variables
    private void swap(int x, int y) {
        x ^= y;
        y ^= x;
        x ^= y;
    }



    // Method to perform union operations based on the adjacency matrix
    private void make() {
        for (int i = 0; i < graph.size(); i++)
            for (int j : graph.get(i))
                Union(i, j);
    }



    // Implementation of the Find operation to determine the representative of the set containing element i
    private int Find(int i) {
        if (set[i] == i) return i;
        return set[i] = Find(set[i]);
    }



    // Implementation of the Union operation to merge the sets containing elements i and j
    private void Union(int i, int j) {

        int x = Find(i), y = Find(j);
        if (x == y)
            return;

        if (rank[x] > rank[y])
            swap(x, y);

        set[y] = x;

        if (rank[x] == rank[y])
            ++rank[y];

        setSize[x] += setSize[y];
        --numSets;
    }




    // Constructor to initialize the disjoint set with size n, height h, and adjacency matrix mat
    public DisjointSet(int n, int h, List<List<Integer>> mat) {
        graph = mat;
        numSets = size = n;
        set = new int[n];
        rank = new int[n];
        setSize = new int[n];

        for (int i = 0; i < size; i++) {
            set[i] = i;
            setSize[i] = 1;
            rank[i] = 0;
        }

        make();
    }



    // Getter method to retrieve the number of sets containing element i
    public int sizeOfSet(int i) {
        return setSize[Find(i)];
    }



    // Getter method to retrieve the current number of sets
    public int getNumSets() {
        return numSets;
    }





    
}
