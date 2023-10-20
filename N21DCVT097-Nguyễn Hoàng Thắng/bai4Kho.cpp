#include <iostream>
#include <vector>
#include <queue>
#include <limits>
// Giải bài toán tìm đường đi ngắn nhất trong đồ thị bằng cách sử dụng thuật toán Dijkstra và đệ quy.
const int INF = std::numeric_limits<int>::max();

// Định nghĩa cấu trúc đỉnh và cạnh
struct Edge {
    int to;
    int weight;
};

using Graph = std::vector<std::vector<Edge>>;

// Hàm đệ quy để in đường đi từ đỉnh gốc đến một đỉnh khác
void printPath(const std::vector<int>& previous, int destination) {
    if (previous[destination] == -1) {
        std::cout << destination << " ";
        return;
    }
    printPath(previous, previous[destination]);
    std::cout << destination << " ";
}

// Thuật toán Dijkstra
void dijkstra(const Graph& graph, int source) {
    int n = graph.size();
    std::vector<int> distance(n, INF);
    std::vector<int> previous(n, -1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    distance[source] = 0;
    pq.push(std::make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push(std::make_pair(distance[v], v));
            }
        }
    }

    // In đường đi ngắn nhất từ đỉnh gốc đến tất cả các đỉnh khác
    for (int i = 0; i < n; ++i) {
        if (i != source) {
            std::cout << "Shortest path from " << source << " to " << i << ": ";
            printPath(previous, i);
            std::cout << "with distance " << distance[i] << std::endl;
        }
    }
}

int main() {
    int n, m; // Số đỉnh và số cạnh
    std::cout << "Enter the number of vertices: ";
    std::cin >> n;
    std::cout << "Enter the number of edges: ";
    std::cin >> m;

    Graph graph(n);

    // Nhập thông tin về các cạnh và trọng số
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cout << "Enter edge (u v w): ";
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int source;
    std::cout << "Enter the source vertex: ";
    std::cin >> source;

    dijkstra(graph, source);

    return 0;
}
