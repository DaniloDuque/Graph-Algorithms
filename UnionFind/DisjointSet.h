#include <iostream>
#include <vector>
using namespace std;





class DisjointSet{

    private:

        int size, numSets ,*set, *rank, *setSize, numFrat = 0, numLoner = 0;
        vector<vector<int>> graph;
        int Find(int);
        void Union(int, int);

    public:

        DisjointSet(int, int, vector<vector<int>>);
        int numDisjointSets(){return numSets;}
        int getNumSets();
        int sizeOfSet(int i){return setSize[i];}
        void make();


};




void DisjointSet::make(){

    for(int i = 0; i<(int) graph.size(); i++)         
        for(int j = 0; j<(int) graph[i].size(); j++)    //O(nlog(n))
            Union(i, graph[i][j]);

    
}



int DisjointSet::getNumSets(){

    return numSets;

}







int DisjointSet::Find(int i){    //O(log(n)) -> O(1)

    if(set[i] == i) return i;
    return set[i] = Find(set[i]);

}





void DisjointSet::Union(int i, int j){     //O(log(n))


    if(set[i] == set[j]) return;
    int x = Find(i), y = Find(j);
    if(rank[x] > rank[y]) swap(x, y);
    set[y] = x;
    if(rank[x] == rank[y]) ++rank[y];
    setSize[x] += setSize[y];
    --numSets;


}





DisjointSet::DisjointSet(int n, int h, vector<vector<int>> mat){  //O(n)

    graph = mat;
    numSets = size = n;
    set = (int*)malloc(n*sizeof(int));
    rank = (int*)malloc(n*sizeof(int));
    setSize = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<size; i++){

        set[i] = i;
        setSize[i] = 1;
        rank[i] = 0;

    } 

}






