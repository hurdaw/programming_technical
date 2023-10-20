#include <iostream>
using namespace std;
void nhapXuat(int a[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
}
void append(int a[100], int &n, int k, int x)
{
    for (int i = n - 1; i >= k; i--)
    { // dịch các phần tử sau k sang phải 1 đơn vị
        a[i + 1] = a[i];
    }
    a[k] = x;
    n++;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[100], n, x = 10, k = 2;
    cin >> n;
    nhapXuat(a, n);
    append(a, n, k, x);
}