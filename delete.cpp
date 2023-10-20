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
void deleting(int a[100], int &n, int &k)
{
    do
    {
        cin >> k;
    } while (k < 0 || k >= n - 1);
    for (int i = k+1; i < n; i++)
    {
        a[i-1]=a[i];
    }
    n--; 
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[100], n, k;
    cin >> n;
    nhapXuat(a, n);
    deleting(a, n, k);
}