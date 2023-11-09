#include <iostream>
#include <queue>
using namespace std;


#define vi vector<int>
#define vvi vector<vi>



vi TopSort(vvi &graph){

    vi in_deg(graph.size(), 0), topSort; queue<int> queue;
    for(int i = 0; i<graph.size(); i++)
        for(int nxt: graph[i])
            in_deg[nxt]++;
    
    for(int i = 0; i<graph.size(); ++i)

        if(!in_deg[i]) queue.push(i);  //pushes vertices with 0 incidence degree

    while(!queue.empty()){

        int curr = queue.front(); queue.pop();
        topSort.push_back(curr);
        for(int nxt: graph[curr]){
            in_deg[nxt]--;
            if(!in_deg[nxt]) queue.push(nxt);

        }

    }if(topSort.size() == graph.size()) return topSort; //graph is a DAG
    return {};

}


int main(){

    int n, m, v1, v2;
    cin>>n>>m;  // n->amount of vertices     m->amount of edges
    vvi graph(n);
    for(int i = 0; i<m; i++){

        cin>>v1>>v2;    //edge from v1 to v2
        graph[v1].push_back(v2);

    }

    vi t = TopSort(graph);
    for(int i: t) cout<<i<<" ";
    cout<<endl;
    return 0;
}
