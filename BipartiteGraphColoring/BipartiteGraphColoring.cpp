#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>


vi memo(10000, 0);


//two colors: 1 and ~1

bool isBipartite(vvi &graph, int i){

    memo[i] = 1; queue<int> bfs; bfs.push(i);

    while(!bfs.empty()){

        int curr = bfs.front(); bfs.pop();

        for(int neigh: graph[curr]){

            if(memo[neigh] == memo[curr]) return false;

            if(!memo[neigh]){

                bfs.push(neigh);
                memo[neigh] = ~memo[curr];

            }

        }

    }return true;


}




int main(){

    int n, m, node1, node2;
    cin>>n>>m;
    vvi graph(n);
    for(int i = 0; i<m; i++){

        cin>>node1>>node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);

    }

    cout<<isBipartite(graph, 0)<<endl;

    return 0;
}
