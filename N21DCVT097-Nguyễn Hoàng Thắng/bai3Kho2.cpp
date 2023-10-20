#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
// Giải bài toán tìm đường đi ngắn nhất trong đồ thị bằng cách sử dụng thuật toán priority queue.
using namespace std;

struct Edge {
    int to, weight;
};

void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distance) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distance[u]) {
            continue;
        }

        for (Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
}

int main() {
    int n, m; // n: number of vertices, m: number of edges
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    vector<int> distance(n, INT_MAX);

    for (int i = 0; i < m; ++i) {
        int u, v, w; // u, v: vertices, w: weight of edge
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // for undirected graph
    }

    int start; // starting vertex
    cin >> start;

    dijkstra(graph, start, distance);

    // Output shortest distances from the starting vertex to all other vertices
    for (int i = 0; i < n; ++i) {
        cout << "Shortest distance from " << start << " to " << i << " is " << distance[i] << endl;
    }

    return 0;
}
