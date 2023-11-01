#include <iostream>
#include <tuple>
#include <queue>
#include <bitset>
using namespace std;

#define edge tuple<int, int, int>
#define duo pair<int, int>
#define vp vector<duo>
#define vi vector<int>
#define vvi vector<vi>
#define minHeap priority_queue<edge, vector<edge>, compare>


bitset<100001> vis(0);


struct compare{

    bool operator()(const edge &a, const edge &b) const{return get<2>(a) > get<2>(b);}

};





vp PrimEdges(vvi &graph, int start){


    minHeap pq; vp MST;
    pq.push({start, start, 0});
    while(!pq.empty()){

        edge curr = pq.top(); pq.pop();
        int node1 = get<0>(curr);
        int node2 = get<1>(curr);
        int cost = get<2>(curr);
        
        if(!vis.test(node2)){
        
            vis.set(node2);
            MST.push_back({node1, node2});
            for(int i = 0; i<graph.size(); ++i)

                if(graph[node2][i] != 1<<30) pq.push({node2, i, graph[node2][i]});

        }
        
    }return MST;

}




int PrimWeight(vvi &graph, int start){

    minHeap pq; int MSTcost = 0;
    pq.push({start, start, 0});

    while(!pq.empty()){

        edge curr = pq.top(); pq.pop();
        int node1 = get<0>(curr);
        int node2 = get<1>(curr);
        int cost = get<2>(curr);
        
        if(!vis.test(node2)){
        
            vis.set(node2);
            MSTcost += cost;
            for(int i = 0; i<graph.size(); ++i)

                if(graph[node2][i] != 1<<30) pq.push({node2, i, graph[node2][i]});

        }
        
    }return MSTcost;

}






int main(){

    int n, m, node1, node2, weight;
    cin>>n>>m;
    vvi graph(n, vi(n, 1<<30));
    for(int i = 0; i<m; ++i){

        cin>>node1>>node2>>weight;
        graph[node1][node2] = weight;
        graph[node2][node1] = weight; // hay que cambiar esto

    }

    return 0;
}





