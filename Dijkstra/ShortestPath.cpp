#include <bits/stdc++.h>
using namespace std;

#define msk bitset<100001>
#define duo pair<int, int>
#define vi vector<int>
#define vvi vector<vector<duo>>
#define minHeap priority_queue<int, vector<int>, compare>


vi memo;
vi prevVertex;  //vector that stores the previous vertex of each vertex




struct compare{

    bool operator()(const int &p1, const int &p2){ return memo[p1] > memo[p2];} 

};





void dijkstra(vvi &graph, int start, int end){

    memo.assign(graph.size(), 1<<30); memo[start] = 0;
    prevVertex.assign(graph.size(), -1); prevVertex[start] = start;
    minHeap pq; pq.push(start);
    msk vis(0); 

    while(!pq.empty()){

        int curr = pq.top();
        pq.pop();  
        vis.set(curr); 
        
        if(curr == end) return;// if current node is the end node, return
        
        for(duo neigh: graph[curr])

            if(!vis.test(neigh.first) && memo[neigh.first] > memo[curr] + neigh.second){

                prevVertex[neigh.first] = curr;   //The previous vertex of neigh.first is curr
                memo[neigh.first] = memo[curr] + neigh.second;
                pq.push(neigh.first);
                
            }

    }return;

    
}




//This constructs the shortest path from start to end
vi shortestPath(int start, int end){

    vi shortP;
    while(end != start){

        shortP.insert(shortP.begin(), end);
        end = prevVertex[end];

    }return shortP;

}






int main(){

    int n, m, node1, node2, weight;
    cin>>n>>m; // n -> amount of vertices    m -> amount of edges
    vvi graph(n);
    for(int i = 0; i<m; i++){

        cin>>node1>>node2>>weight;   // node1 -> initial vertex   node2 -> final vertex    weight -> cost of going from node1 to node2
        graph[node1].push_back({node2, weight});

    }

    
    dijkstra(graph, 0, 4);  // 0->start node   4->end node
    vi shortP = shortestPath(0, 4);
    for(int i: shortP) cout<<i<<" ";
    cout<<'\n';

}







/*

This program finds the shortest path from a start node to an end node in a graph.

*/
