#include <iostream>
#include <vector>
using namespace std;


#define duo pair<int, int>
#define vvi vector<vector<duo>>
#define MINF -(1<<30)



int * makeArr(int n, int start){

    int * arr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++) arr[i] = 1<<30;
    arr[start] = 0;
    return arr;

}




int * infiniteCycles(vvi &graph, int * &minRoutes){

    for(int i = 0; i<graph.size()-1; ++i)

        for(int u = 0; u<graph.size(); ++u)

            for(duo edge: graph[u])

                if(minRoutes[edge.first] > minRoutes[u] + edge.second) minRoutes[edge.first] = MINF; //if there is change, then we find a infinite cycle

    return minRoutes;

}




int * BellmanFord(vvi &graph, int start){

    int * minRoutes = makeArr(graph.size(), start);

    for(int i = 0; i<graph.size()-1; ++i)

        for(int u = 0; u<graph.size(); ++u)

            for(duo edge: graph[u])

                if(minRoutes[edge.first] > minRoutes[u] + edge.second)

                    minRoutes[edge.first] = minRoutes[u] + edge.second;

    return infiniteCycles(graph, minRoutes);

}





int main(){

    int n, m, node1, node2, weight;
    cin>>n>>m;   // n->amount of vertices    m->amount of edges
    vvi graph(n);
    for(int i = 0; i<m; i++){

        cin>>node1>>node2>>weight;  //from node1 to node2 with cost = weight
        graph[node1].push_back({node2, weight});

    }
    int * bell = BellmanFord(graph, 0);
    for(int i = 0; i<n; i++) cout<<bell[i]<<" ";
    cout<<endl;
    return 0;

}



