#include <bits/stdc++.h>
using namespace std;

#define edge tuple<int, int, int>
#define duo pair<int, int>
#define vi vector<duo>
#define vvi vector<vi>
#define minHeap priority_queue<edge, vector<edge>, compare>


bitset<100001> vis(0);


struct compare{

    bool operator()(const edge &a, const edge &b) const{return get<2>(a) > get<2>(b);}

};





vi PrimEdges(vvi &graph, int start){

    minHeap pq; vi MST; int visits=1;
    pq.push({start, start, 0});

    while(!pq.empty()){


        edge curr = pq.top(); pq.pop();
        int node1 = get<0>(curr);
        int node2 = get<1>(curr);
        int cost = get<2>(curr);
        
        if(!vis.test(node2)){
        
            vis.set(node2);
            MST.push_back({node1, node2});
            if(++visits == graph.size()) return MST; // if we visited all nodes, return MST

            for(duo neigh: graph[node2])

               pq.push({node2, neigh.first, neigh.second});

        }
        
    }return MST;

}




int PrimWeight(vvi &graph, int start){

    minHeap pq; int MSTcost = 0; int visits=1;
    pq.push({start, start, 0});

    while(!pq.empty()){


        edge curr = pq.top(); pq.pop();
        int node2 = get<1>(curr);
        int cost = get<2>(curr);
        
        if(!vis.test(node2)){
        
            vis.set(node2);
            MSTcost += cost;
            if(++visits == graph.size()) return MSTcost; // if we visited all nodes, return MSTcost

            for(duo neigh: graph[node2])

               pq.push({node2, neigh.first, neigh.second});

        }
        
    }return 1<<30;

}






int main(){

    int n, m, node1, node2, weight;
    cin>>n>>m; // n->amount of vertices     m->amount of edges
    vvi graph(n);
    for(int i = 0; i<m; ++i){

        cin>>node1>>node2>>weight;    // from node1 to node2 with cost = weight
        graph[node1].push_back({node2, weight});

    }

    for(duo k: PrimEdges(graph, 0)) cout<<'('<<k.first<<", "<<k.second<<")  ";
    cout<<endl;

    return 0;
}


