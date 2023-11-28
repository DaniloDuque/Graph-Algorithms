#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {

    private:
        int size, numSets, *set, *rank, *setSize, numFrat = 0, numLoner = 0;
        vector<vector<int>> graph;
        
        // Find operation to determine the representative of the set containing element i
        int Find(int);
        
        // Union operation to merge the sets containing elements i and j
        void Union(int, int);
    
    public:
    
        // Constructor to initialize the disjoint set with size n, height h, and adjacency matrix mat
        DisjointSet(int, int, vector<vector<int>>);
        
        // Method to perform union operations based on the adjacency matrix
        void make();
        
        // Getter method to retrieve the number of sets containing element i
        int sizeOfSet(int i) { return setSize[Find(i)]; }
        
        // Getter method to retrieve the current number of sets
        int getNumSets();

};






// Implementation of the make method to perform union operations based on the adjacency matrix
void DisjointSet::make() {
    for (int i = 0; i < (int)graph.size(); i++)
        for (int j = 0; j < (int)graph[i].size(); j++)
            Union(i, graph[i][j]);
}







// Getter method to retrieve the current number of sets
int DisjointSet::getNumSets() {
    return numSets;
}







// Implementation of the Find operation to determine the representative of the set containing element i
int DisjointSet::Find(int i) {
    if (set[i] == i)
        return i;
    return set[i] = Find(set[i]);
}






// Implementation of the Union operation to merge the sets containing elements i and j
void DisjointSet::Union(int i, int j) {
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
DisjointSet::DisjointSet(int n, int h, vector<vector<int>> mat) {
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
}
