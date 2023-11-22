#include <bits/stdc++.h>
using namespace std;


const int INF = 1<<30;
#define duo pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vvp vector<vector<duo>>
#define msk bitset<5000>
#define minHeap priority_queue<int, vector<int>, compare>



vi memo;
msk vis(0);


struct compare{

    bool operator()(const int &p1, const int &p2){ return memo[p1] > memo[p2]; } 

};





vi BellmanFord(vvp &graph){

    int start = graph.size(); graph.push_back({}); 
    for(int i = 0; i<graph.size(); i++) graph[start].push_back({i, 0});    //Here we create a node *s* and connect s to every vertex
    vi minRoutes(graph.size(), INF); minRoutes[start] = 0;

    for(int i = 0; i<graph.size()-1; ++i)                                  //Then calculate minRoutes from s to every vertex using Bellman-Ford

        for(int u = 0; u<graph.size(); ++u)

            for(duo edge: graph[u])

                if(minRoutes[edge.first] > minRoutes[u] + edge.second)

                    minRoutes[edge.first] = minRoutes[u] + edge.second;

    
    return minRoutes;

}







void changeCosts(vvp &graph, vi &minRoutes){

    graph.erase(graph.end()-1);                                   //To make it possible to apply dijkstra we, modify every cost that Bellman-Ford returned
    for(int i = 0; i<graph.size(); i++)
        for(int j = 0; j<graph[i].size(); j++)
            graph[i][j].second += minRoutes[i] - minRoutes[j];   //This ensurses that there is no negative weight edge

}







vi dijkstra(vvp &graph, int i){

    memo.assign(graph.size(), INF); memo[i] = 0; int visits=1;
    minHeap pq; pq.push(i);
    vis.reset(); 

    while(!pq.empty()){

        int curr = pq.top(); pq.pop();  
        vis.set(curr); 

        if(++visits == graph.size()) return memo; // if we visited all nodes, return routes
        
        for(duo neigh: graph[curr])

            if(!vis.test(neigh.first) && memo[neigh.first] > memo[curr] + neigh.second){

                memo[neigh.first] = memo[curr] + neigh.second;
                pq.push(neigh.first);

            }

    }return memo;
    
}








vvi dijkstraFromAllNodes(vvp &graph){

    vvi result(graph.size());
    for(int i = 0; i<graph.size(); i++){

        result[i] = dijkstra(graph, i);

    }return result;

}




vvi Johnson(vvp &graph){

    vi minRoutes = BellmanFord(graph);     
    changeCosts(graph, minRoutes);
    vvi allMinRoutes = dijkstraFromAllNodes(graph);
    for(int i = 0; i<graph.size(); i++)
        for(duo vertex: graph[i])
            allMinRoutes[i][vertex.first] += minRoutes[i] - minRoutes[vertex.first]; //Here we Undo, the changes that were made in "changeCosts"
    return allMinRoutes;
    
}














int main(){

    int n, m, node1, node2, weight;
    cin>>n>>m; // n->amount of vertices    m->amount of edges
    vvp graph(n);
    for(int i = 0; i<m; i++){

        cin>>node1>>node2>>weight;       //from node1 to node2 with weight cost
        graph[node1].push_back({node2, weight});

    }
    vvi johnson = Johnson(graph);
    for(vi row: johnson){
        for(int i: row) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}
