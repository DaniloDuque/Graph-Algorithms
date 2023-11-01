#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;


#define edge tuple<int, int, int>
#define vi vector<int>
#define vvi vector<vi>
#define ve vector<edge>




bool compareEdges(edge &a, edge &b){

    return get<2>(a) < get<2>(b);   //function to compare to edges based on their weight

}



int Find(int node, vi &DS){

    if(DS[node] == node) return node;          //Find function from UnionFind algorithm
    return DS[node] = Find(DS[node], DS);

}



ve KruskalEdges(ve &Edges, vvi &graph, vi &DS, int start){

    ve MST;
    sort(Edges.begin(), Edges.end(), compareEdges);

    for(edge rel: Edges){


        int parU = Find(get<0>(rel), DS);
        int parV = Find(get<1>(rel), DS);
        int cost = get<2>(rel);
        if(parU != parV){

            MST.push_back(rel);      //Union function
            DS[parU] = parV;

        }

    }return MST;

}






int KruskalCost(ve &Edges, vvi &graph, vi &DS, int start){

    sort(Edges.begin(), Edges.end(), compareEdges);

    int MSTcost = 0;

    for(edge rel: Edges){


        int parU = Find(get<0>(rel), DS);
        int parV = Find(get<1>(rel), DS);
        int cost = get<2>(rel);
        if(parU != parV){

            MSTcost += cost;      //Union function
            DS[parU] = parV;

        }

    }return MSTcost;

}






int main(){

    int n, m, node1, node2, cost;
    cin>>n>>m;
    ve Edges;
    vvi graph(n, vector<int>(n, 1<<30));
    vi DS; for(int i = 0; i<n; i++) DS.push_back(i);
    

    for(int i = 0; i<m; i++){

        cin>>node1>>node2>>cost;
        graph[node1][node2] = cost;
        graph[node2][node1] = cost;
        Edges.push_back({node1, node2, cost});
        Edges.push_back({node2, node1, cost});

    }

    return 0;
}

