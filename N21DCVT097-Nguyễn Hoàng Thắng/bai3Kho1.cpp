#include <iostream>
#include <vector>
#include <queue>
#include <climits>
// Giải bài toán tìm đường đi ngắn nhất trong đồ thị bằng cách sử dụng thuật toán Dijkstra 
using namespace std;

// Định nghĩa cấu trúc biểu diễn đồ thị
struct Edge {
    int to;
    int weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

// Định nghĩa hàm so sánh để sử dụng priority queue
struct Compare {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

// Thuật toán Dijkstra
void dijkstra(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    priority_queue<Edge, vector<Edge>, Compare> pq;

    distance[start] = 0;
    pq.push(Edge(start, 0));

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();
        int u = current.to;
        int dist = current.weight;

        // Nếu có đường đi ngắn hơn đến u, bỏ qua
        if (dist > distance[u]) {
            continue;
        }

        for (Edge& neighbor : graph[u]) {
            int v = neighbor.to;
            int weight = neighbor.weight;
            int newDist = distance[u] + weight;

            if (newDist < distance[v]) {
                distance[v] = newDist;
                pq.push(Edge(v, newDist));
            }
        }
    }

    // In ra độ dài ngắn nhất từ đỉnh start đến các đỉnh còn lại
    for (int i = 0; i < n; i++) {
        cout << "Shortest distance from " << start << " to " << i << " is " << distance[i] << endl;
    }
}

int main() {
    int n = 6; // Số đỉnh
    vector<vector<Edge>> graph(n);

    // Thêm các cạnh và trọng số
    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));
    graph[1].push_back(Edge(3, 3));
    graph[2].push_back(Edge(1, 1));
    graph[2].push_back(Edge(3, 5));
    graph[3].push_back(Edge(4, 1));
    graph[4].push_back(Edge(5, 6));

    int start = 0; // Đỉnh xuất phát
    dijkstra(graph, start);

    return 0;
}
