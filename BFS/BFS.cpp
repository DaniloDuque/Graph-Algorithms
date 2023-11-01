#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

bitset<100001> vis(0);
queue<int> bfs;

#define vvi vector<vector<int>>

    


void BFS(vvi &graph, int start){

    
    cout<<start<<" ";
    bfs.push(start); vis.set(start);

    while(!bfs.empty()){

        int curr = bfs.front();
        bfs.pop();

        for(int neigh: graph[curr]){

            if(!vis.test(neigh)){

                cout<<neigh<<" ";
                bfs.push(neigh); vis.set(neigh);

            }
        }

    }cout<<'\n';

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

    BFS(graph, K);
    return 0;
}




