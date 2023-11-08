#include <bits/stdc++.h>
using namespace std;

#define msk bitset<100001>
#define duo pair<int, int>
#define vvi vector<vector<duo>>
#define minHeap priority_queue<int, vector<int>, compare>


vector<int> memo;

struct compare{

    bool operator()(const int &p1, const int &p2){ return memo[p1] > memo[p2];} 

};





vector<int> dijkstra(vvi &graph, int i){

    memo.assign(graph.size(), 1<<30); memo[i] = 0;
    minHeap pq; pq.push(i);
    msk vis(0); 
    
    while(!pq.empty()){

        int curr = pq.top();
        pq.pop();  
        vis.set(curr); 
        
        if(vis.count() == graph.size()) return memo; // if we visited all nodes, return routes
        
        for(duo neigh: graph[curr])

            if(!vis.test(neigh.first) && memo[neigh.first] > memo[curr] + neigh.second){

                memo[neigh.first] = memo[curr] + neigh.second;
                pq.push(neigh.first);
            }

    }return memo;
    
}




int main(){

    int n, m, node1, node2, weight;
    cin>>n>>m;
    vvi graph(n);
    for(int i = 0; i<m; i++){

        cin>>node1>>node2>>weight;
        graph[node1].push_back({node2, weight});

    }

    vector<int> routes = dijkstra(graph, 0);
    for(int i = 0; i<graph.size(); i++) cout<<routes[i]<<" ";
    cout<<'\n';


}
