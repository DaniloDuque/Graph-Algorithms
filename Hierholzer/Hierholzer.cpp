#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define pv pair<vector<int>, vector<int>>
#define vi vector<int>
#define vvi vector<vector<int>>




pv countDegrees(vvi &graph){

    vi in_Deg(graph.size(), 0), out_Deg(graph.size(), 0);

    for(int i = 0; i<graph.size(); i++){

        out_Deg[i] += graph[i].size();
        for(int j: graph[i]) in_Deg[j]++;        
    
    }return {in_Deg, out_Deg};

}



bool hasEulerianPath(int size, vi &in_Deg, vi &out_Deg){

    int strtV = 0, endV = 0;

    for(int i = 0; i<size; ++i){

        if(abs(in_Deg[i]-out_Deg[i]) > 1) return false;    // if the diff between degs in a vertex is more than one, then no posibble eulerian path

        else if(out_Deg[i] - in_Deg[i] == 1) strtV++;   //if out > in, then we found a possible start vertex;

        else if(in_Deg[i] - out_Deg[i] == 1) endV++;    //if in > out, then we found a possible end vertex;

    }return (!strtV && !endV) || (strtV == endV == 1);  //if there is one end vertex, then there has to be one and only one start vertex

}






int startVertex(vvi &graph, vi &in_Deg, vi &out_Deg){

    int strtV = 0;
    for(int i = 0; i<graph.size(); ++i){

        if(out_Deg[i] - in_Deg[i] == 1) return i;   //we found a start vertex

        if(out_Deg[i] != 0) strtV = i;

    }return strtV;

}



stack<int> path;


void dfs(vvi &graph, vi &out_Deg, int curr){

    while(out_Deg[curr]){

        int nxt = graph[curr].back();
        --out_Deg[curr]; graph[curr].pop_back(); //we will visit vertex nxt, so, eliminate the edge from curr to nxt
        dfs(graph, out_Deg, nxt);

    }path.push(curr);

}




stack<int> findEulerianPath(vvi &graph){

    pv Degrees = countDegrees(graph);
    if(!hasEulerianPath(graph.size(), Degrees.first, Degrees.second)) return {};
    dfs(graph, Degrees.second, startVertex(graph, Degrees.first, Degrees.second));
    return path;

}




int main(){

    int n, m, v1, v2;
    cin>>n>>m;   // n-> amount of vertices       m-> amount of edges
    vvi graph(n);
    for(int i = 0; i<m; i++){

        cin>>v1>>v2;   //edge v1->v2
        graph[v1].push_back(v2);

    }stack<int> eulerian = findEulerianPath(graph);
    
    while(!eulerian.empty()){

        cout<<eulerian.top()<<" ";
        eulerian.pop();
        
    }cout<<endl;
    return 0;
}
