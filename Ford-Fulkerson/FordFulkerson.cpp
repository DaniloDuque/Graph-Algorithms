#include <bits/stdc++.h>
using namespace std;


#define msk bitset<5000>
#define vi vector<int>
#define vvi vector<vi>


msk vis(0);




bool existsPath(vvi &graph, vi &prevVertex, int curr, int sink){

    vis.set(curr);

    if(curr == sink) return true;

    for(int i = 0; i<graph.size(); ++i)

        if(!vis.test(i) && graph[curr][i] > 0){

            prevVertex[i] = curr;
            if(existsPath(graph, prevVertex, i, sink)) return true;

        }

    return false;

}




int maxFlow(vvi &graph, int source, int sink){
    
    int MaxFlow = 0;
    vi prevVertex(graph.size(), -1);

    while(existsPath(graph, prevVertex, source, sink)){      //while there is a path from source to sink

        int pathMinFlow = INT_MAX;

        for(int v = sink; v != source; v = prevVertex[v])    //find the bottleneck value
            pathMinFlow = min(pathMinFlow, graph[prevVertex[v]][v]);


        for(int v = sink; v != source; v = prevVertex[v]){   //augment the path

            graph[prevVertex[v]][v] -= pathMinFlow;
            graph[v][prevVertex[v]] += pathMinFlow;

        }MaxFlow += pathMinFlow;
        prevVertex.assign(graph.size(), -1);
        vis.reset();

    }return MaxFlow;


}





int main(){

    int n, m, v1, v2, source, sink, flow; 
    cin>>n>>m>>source>>sink; // n->amount of vertices   m->amount of edges
    vvi graph(n, vi(n, 0));
    for(int i = 0; i<m; i++){

        cin>>v1>>v2>>flow;   //from v1 to v2 has flow as maximum flow
        graph[v1][v2] = flow;

    }cout<<maxFlow(graph, source, sink)<<'\n';
    return 0;

}
