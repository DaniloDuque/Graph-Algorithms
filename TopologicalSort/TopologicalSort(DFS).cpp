#include <bits/stdc++.h>
using namespace std;

#define msk bitset<100001>
#define vi vector<int>
#define vvi vector<vi>

void topSortAux(vvi &graph, stack<int> &topSort, msk &vis, int start) {
    if (vis.test(start)) return;
    vis.set(start);
    for (int neigh : graph[start]) {
        if (!vis.test(neigh)) topSortAux(graph, topSort, vis, neigh);
    }
    topSort.push(start); 
}






stack<int> TopologicalSort(vvi &graph) {
    stack<int> topSort;
    msk vis(0);
    for (int i = 0; i < graph.size(); i++)
        if (!vis.test(i)) topSortAux(graph, topSort, vis, i);
    return topSort;
}







// Important: the graph HAS to be directed and acyclic

int main() {
    int n, m, node1, node2;
    cin >> n >> m;  // n->amount of vertices    m->amount of edges
    vvi graph(n);
    msk vis(0);

    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;  // from node1 to node2
        graph[node1].push_back(node2);
    }

    stack<int> topSort = TopologicalSort(graph);
    while (!topSort.empty()) {
        cout << topSort.top() << " ";
        topSort.pop();
    }
    cout << endl;
    return 0;
}
