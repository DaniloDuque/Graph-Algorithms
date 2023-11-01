#include <iostream>
#include <vector>
using namespace std;


#define vvi vector<vector<int>>





void FloydWarshall(vvi &graph) {


    for(int k = 0; k<graph.size(); k++)

        for(int i = 0; i<graph.size(); i++)

            for(int j = 0; j<graph.size(); j++)

                if(graph[i][k] != 1<<30 && graph[k][j] != 1<<30 && graph[i][k] + graph[k][j] < graph[i][j]) 

                    graph[i][j] = graph[i][k] + graph[k][j];
    
}


int main(){

    int n, m, node1, node2, weight;
    
    cin>>n>>m;
    vvi graph(n, vector<int>(n, 1<<30));
    for(int i = 0; i<n; i++) graph[i][i] = 0;

    for(int i = 0; i<m; i++){

        cin>>node1>>node2>>weight;
        graph[node1][node2] = weight;

    }

    FloydWarshall(graph);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<graph[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}



