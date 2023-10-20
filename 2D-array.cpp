#include <iostream>
using namespace std;
// cách cơ bản
void tongKhoi(int a[][100], int &m, int &n)
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int q, s = 0;
    cin >> q;
    while (q--)
    {
        int h1, h2, c1, c2;
        cin >> h1 >> h2 >> c1 >> c2;
        for (int i = h1; i <= h2; i++)
        {
            for (int j = c1; j <= c2; j++)
            {
                s += a[i][j];
            }
        }
    }
    cout << s;
}
// cách dùng prefix sum
void prefix(int a[][100], int &m, int &n)
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int pre[m+1][n+1] = {0};
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int h1, h2, c1, c2;
        cin >> h1 >> h2 >> c1 >> c2;
        cout << (pre[h2][c2] - pre[h1 - 1][c2] - pre[h2][c1 - 1] + pre[h1 - 1][c1 - 1]) << endl;
    }
}
int main()
{
    int m, n, a[100][100];
    //tongKhoi(a, m, n);
    prefix(a, m, n);
}