#include <iostream>
#include <vector>
#include <bitset>
using namespace std;


bitset<100001> vis(0);

#define vvi vector<vector<int>>



void DFS(vvi &graph, int start){

    if(vis.test(start)) return;
    vis.set(start);
    cout<<start<<" ";
    for(int neigh: graph[start]) DFS(graph, neigh);

}




int main(){

    int A, C, K, x, y;
    cin>>A>>C>>K;
    vector<vector<int>> graph(A, vector<int>(0));
    

    for(int i = 0; i<C; i++){
        
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);

    }

    DFS(graph, K);

    return 0;
}
