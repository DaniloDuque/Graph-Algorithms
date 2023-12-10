#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>





bitset<100001> visited(0);
vvi graph;
vi ids, low, depth;
int currentDepth;
unordered_set<int> articulationPoints;







void dfs(int current, int parent) {

    visited.set(current);
    ids[current] = low[current] = currentDepth++;
    int childCount = 0;
    bool isArticulationPoint = false;

    for (int neighbor : graph[current])

        if (!visited.test(neighbor)){

            childCount++;
            dfs(neighbor, current);
            low[current] = min(low[current], low[neighbor]);

            if (low[neighbor] >= ids[current]) isArticulationPoint = true;
            
        }else low[current] = min(low[current], ids[neighbor]);
        
    if ((parent == -1 && childCount > 1) || (parent != -1 && isArticulationPoint)){  //if current is root and has more than one child, or if current is an articulation point
        articulationPoints.insert(current);
    }

}













unordered_set<int> findArticulationPoints(vvi& graph) {

    ids.assign(graph.size(), -1);
    low.assign(graph.size(), 0);
    visited.reset();
    currentDepth = 0;
    articulationPoints.clear();

    for (int i = 0; i < graph.size(); ++i) 
        if (!visited.test(i)) 
            dfs(i, -1);
        
    return articulationPoints;

}








int main() {


    int n, m, node1, node2;
    cin >> n >> m;
    graph.assign(n, vi(0));

    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1); // Add this line for undirected graph
    }

    auto articulationPoints = findArticulationPoints(graph);
    for (int point : articulationPoints) cout << point << " ";
    cout << '\n';
    return 0;
    

}
