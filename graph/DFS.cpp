#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[100];
int a[100][100];
bool visited[100], check[100];
// input
// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9
void input_dsk()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void DFS(int u)
{
    cout << u << " ";
    // đánh dấu là u đã được thăm
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS(v);
        }
    }
}
void input_mtk()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
}
void DFS_mtk(int u)
{
    cout << u << " ";
    check[u] = true;
    for (int v = 1; v <= n; v++)
    {
        if (a[u][v] == 1 && check[v] == false)
        {
            DFS_mtk(v);
        }
    }
}
int main()
{
    input_dsk();
    input_mtk();
    clock_t start, end;
    start = clock();
    DFS(1);
    end = clock();
    double time_used_1 = (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl
         << time_used_1;
    cout << endl;
    start = clock();
    DFS_mtk(1);
    end = clock();
    double time_used_2 = (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl
         << time_used_2;
}