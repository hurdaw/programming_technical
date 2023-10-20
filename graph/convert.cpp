#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];       // lưu danh sách kề
vector<pair<int, int>> edge; // lưu danh sách cạnh
// chuyển đổi từ danh sách cạnh sang ma trận kề
void maTranke(int a[100][100], int &n, int &m)
{
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
// chuyển từ danh sách cạnh sang danh sách kề
void danhSachKe(vector<int> adj[], int &n, int &m)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
// chuyển đổi từ ma trận kề sang danh sách cạnh
void danhSachcanh(vector<pair<int, int>> edge, int a[100][100], int &n, int &m)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] && i < j)
            {
                edge.push_back({i, j});
            }
        }
    }
    for (auto it : edge)
    {
        cout << it.first << " " << it.second << endl;
    }
}
// chuyển từ ma trận kề sang danh sách kề
void mtk_to_dsk(vector<int> adj[], int a[][100], int &n)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j])
            {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, m;
    int a[100][100];
    //maTranke(a, n, m);
    // danhSachKe(adj, n, m);
    // danhSachcanh(edge, a, n, m);
    mtk_to_dsk(adj, a, m);
}