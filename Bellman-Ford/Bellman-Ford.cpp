#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

#define duo pair<int, int>
#define vvi vector<vector<duo>>




vector<int> infiniteCycles(vvi &graph, vector<int> &minRoutes) {
    for (int i = 0; i < graph.size() - 1; ++i)
        for (int u = 0; u < graph.size(); ++u)
            for (duo edge : graph[u])
                if (minRoutes[edge.first] > minRoutes[u] + edge.second)
                    minRoutes[edge.first] = INT_MIN; // Using INT_MIN for infinite cycles
    return minRoutes;
}




vector<int> BellmanFord(vvi &graph, int start) {
    
    vector<int> minRoutes(graph.size(), INT_MAX);
    minRoutes[start] = 0;
    
    for (int i = 0; i < graph.size() - 1; ++i)
        for (int u = 0; u < graph.size(); ++u)
            for (duo edge : graph[u])
                if (minRoutes[edge.first] > minRoutes[u] + edge.second)
                    minRoutes[edge.first] = minRoutes[u] + edge.second;
    return infiniteCycles(graph, minRoutes);
    
}




int main() {
    int n, m, node1, node2, weight;
    cin >> n >> m; // n->amount of vertices    m->amount of edges
    vvi graph(n);
    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2 >> weight; // from node1 to node2 with cost = weight
        graph[node1].push_back({node2, weight});
    }

    vector<int> bell = BellmanFord(graph, 0);
    for (int i : bell)
        cout << i << " ";
    cout << endl;
    return 0;
}
