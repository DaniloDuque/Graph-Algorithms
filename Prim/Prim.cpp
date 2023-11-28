#include <bits/stdc++.h>
using namespace std;



typedef tuple<int, int, int> edge;
typedef pair<int, int> duo;
typedef vector<duo> vi;
typedef vector<vi> vvi;
typedef priority_queue<edge, vector<edge>, greater<edge>> minHeap;



struct compare {
    bool operator()(const edge &a, const edge &b) const {
        return get<2>(a) > get<2>(b);
    }
};



bitset<100001> vis;






vi PrimEdges(vvi &graph, int start) {

    minHeap pq; vi MST; int visits = 0;
    pq.emplace(start, start, 0);

    while (!pq.empty()) {

        edge curr = pq.top();
        pq.pop();
        int node1 = get<0>(curr);
        int node2 = get<1>(curr);
        int cost = get<2>(curr);

        if (!vis.test(node2)) {
            vis.set(node2);
            MST.emplace_back(node1, node2);
            if (++visits == graph.size()) return MST;

            for (duo neigh : graph[node2])
                pq.emplace(node2, neigh.first, neigh.second);
        }
    }return {}; //there is no MST
}








int PrimWeight(vvi &graph, int start) {

    minHeap pq; int MSTcost = 0; int visits = 0;
    pq.emplace(start, start, 0);

    while (!pq.empty()) {
        edge curr = pq.top();
        pq.pop();
        int node2 = get<1>(curr);
        int cost = get<2>(curr);

        if (!vis.test(node2)) {
            vis.set(node2);
            MSTcost += cost;
            if (++visits == graph.size()) return MSTcost;  //if we have visited all nodes, return the cost

            for (duo neigh : graph[node2])
                pq.emplace(node2, neigh.first, neigh.second);
        }
    }return 1 << 30;
}





int main() {

    int n, m, node1, node2, weight;
    cin >> n >> m;
    vvi graph(n);
    for (int i = 0; i < m; ++i) {
        cin >> node1 >> node2 >> weight;
        graph[node1].emplace_back(node2, weight);
    }

    vis.reset();  // Reset the bitset before each use
    for (duo k : PrimEdges(graph, 0))
        cout << '(' << k.first << ", " << k.second << ")  ";
    cout << endl;

    return 0;

}
