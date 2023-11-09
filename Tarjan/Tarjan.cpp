#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>


bitset<100001> onStack(0);
vvi graph;
vi ids, low;
stack<int> st;




void dfs(int start, int &numSCC){

    st.push(start);
    onStack.set(start);
    ids[start] = low[start] = start;

    for(int neigh:graph[start]){

        if(ids[neigh] == -1) dfs(neigh, numSCC);
        if(onStack.test(neigh)) low[start] = min(low[start], low[neigh]);
            
    }
    if(ids[start] == low[start]){  //if start is the root vertex of this SCC
       
        while(!st.empty()){  //clear the stack until we encounter the root of the SCC

            int curr = st.top(); st.pop();
            onStack.flip(curr);
            low[curr] = ids[start];
            if(curr == start) break;  

        }numSCC++;

    }

}






int Tarjan(vvi &graph){

    int numSCC = 0;
    ids.assign(graph.size(), -1);
    low.assign(graph.size(), 0);

    for(int i = 0; i<graph.size(); ++i)

        if(ids[i] == -1)  //if not visited, then visit it

            dfs(i, numSCC);

    
    // for(int k: low) cout<<k<<" ";
    // cout<<endl;
    return numSCC;  //number of SCCs in the graph
    
}



int main(){

    int n, m, node1, node2;
    cin>>n>>m;
    graph.assign(n, vi(0));
    for(int i = 0; i<m; i++){

        cin>>node1>>node2;
        graph[node1].push_back(node2);

    }
    cout<<Tarjan(graph)<<endl;

    return 0;
}

