#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

#define msk bitset<100001>
#define duo pair<int, int>
#define vvi vector<vector<duo>>
#define minHeap priority_queue<duo, vector<duo>, compare>



struct compare{

    bool operator()(const duo &p1, const duo &p2){ return p1.second > p2.second; } 

};





int * makeArr(int n){

    int * minRoutes = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++) minRoutes[i] = 1<<30;
    return minRoutes;
    
}






int * dijkstra(vvi &graph, int i){

    int * minRoutes = makeArr(graph.size()); minRoutes[i] = 0;
    minHeap pq; pq.push({i, 0});
    msk vis(0); 
    

    while(!pq.empty()){

        int curr = pq.top().first;
        pq.pop();  
        vis.set(curr); 
        
        if(vis.count() == graph.size()) return minRoutes; // if we visited all nodes, return routes
        
        for(duo neigh: graph[curr])

            if(!vis.test(neigh.first) && minRoutes[neigh.first] > minRoutes[curr] + neigh.second)

                pq.push({neigh.first, minRoutes[neigh.first] = minRoutes[curr] + neigh.second});


    }return minRoutes;
    
}




int main(){

    int n, m, node1, node2, weight;
    cin>>n>>m;
    vvi graph(n);
    for(int i = 0; i<m; i++){

        cin>>node1>>node2>>weight;
        graph[node1].push_back({node2, weight});

    }

    int * routes = dijkstra(graph, 0);
    for(int i = 0; i<graph.size(); i++) cout<<routes[i]<<" ";
    cout<<'\n';

    
    

}






