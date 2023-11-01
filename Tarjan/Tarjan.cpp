#include <iostream>
#include <vector>
#include <bitset>
#include <stack>

using namespace std;



#define vi vector<int>
#define vvi vector<vi>


bitset<100001> onStack(0);
vvi graph;
vi ids, low;
stack<int> st;
int id = 0;




void dfs(int start, int &numSCC){

    st.push(start);
    onStack.set(start);
    ids[start] = low[start] = id++;

    for(int neigh:graph[start]){

        if(ids[neigh] == -1) dfs(neigh, numSCC);
        if(onStack.test(neigh)) low[start] = min(low[start], low[neigh]);

    }

    if(ids[start] == low[start]){

        while(!st.empty()){

            int curr = st.top(); st.pop();
            onStack.reset(curr);
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

        if(ids[i] == -1)

            dfs(i, numSCC);

    // for(int k: low) cout<<k<<" ";
    // cout<<endl;
    return numSCC;
    
}



int main(){

    int n, m, node1, node2;
    cin>>n>>m;
    graph.resize(n);
    for(int i = 0; i<m; i++){

        cin>>node1>>node2;
        graph[node1].push_back(node2);

    }

    cout<<Tarjan(graph)<<endl;


    return 0;
}




