#include <bits/stdc++.h>
using namespace std;


#define edge tuple<int, int, int>
#define vi vector<int>
#define ve vector<edge>




bool compareEdges(edge &a, edge &b){

    return get<2>(a) < get<2>(b);   //function to compare to edges based on their weight

}



int Find(int node, vi &DS){

    if(DS[node] == node) return node;          //Find function from UnionFind algorithm
    return DS[node] = Find(DS[node], DS);

}



ve KruskalEdges(ve &Edges, vi &DS, int start){

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






int KruskalCost(ve &Edges, vi &DS, int start){

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
    cin>>n>>m; // n->amount of vertices    m->amount of edges
    ve Edges;   // vector of edges
    vi DS; for(int i = 0; i<n; i++) DS.push_back(i);
    

    for(int i = 0; i<m; i++){

        cin>>node1>>node2>>cost;   //the edge (node1, node2), has a cost = weight
        Edges.push_back({node1, node2, cost});
        Edges.push_back({node2, node1, cost});  //undirected graph

    }

    cout<<KruskalCost(Edges, DS, 0)<<'\n';

    return 0;
}

