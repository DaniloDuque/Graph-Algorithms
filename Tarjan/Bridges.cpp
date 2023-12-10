#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vp vector<pair<int, int>>





bitset<100001> onStack(0);
vvi graph;
vi ids, low;
stack<int> st;
vp bridges;








void dfs(int start) {

    st.push(start);
    onStack.set(start);
    ids[start] = low[start] = start;

    for(int neigh : graph[start]){

        if (ids[neigh] == -1) {     //if neighbor not visited, then visit it
            dfs(neigh);
            low[start] = min(low[start], low[neigh]);   //then, low value of start becomes the min between low[start] and low[neighbor]

            if (low[neigh] > ids[start]) bridges.push_back({start, neigh});  // Check for bridge

        } else if (onStack.test(neigh))   
            low[start] = min(low[start], ids[neigh]);
    }


    while (!st.empty()) {    //empty the stack
        int curr = st.top();
        st.pop();
        onStack.flip(curr);
    }


}










vp findBridges(vvi& graph) {

    ids.assign(graph.size(), -1);
    low.assign(graph.size(), 0);
    bridges.clear();

    for (int i = 0; i < graph.size(); ++i)
        if (ids[i] == -1)  // if not visited, then visit it
            dfs(i);

    return bridges;

}










int main() {

    int n, m, node1, node2;
    cin >> n >> m;
    graph.assign(n, vi(0));

    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
    }

    for (pair<int, int> duo : findBridges(graph)) cout << '(' << duo.first << ", " << duo.second << ") ";
    cout << '\n';
    return 0;
}
