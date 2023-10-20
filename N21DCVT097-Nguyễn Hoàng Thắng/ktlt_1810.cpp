#include <bits/stdc++.h>
using namespace std;
int n, a[100], b[100];
void nhapMang(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void distribution(int a[], int b[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    for (int i = 0; i <= max; i++)
    {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    for (int i = 0; i <= max; i++)
    {
        if (b[i] > 0)
        {
            // printf("%d - %d; ", i, b[i]);
            cout << i << " - " << b[i] << endl;
        }
    }
}
// lọc ra số nguyên tố từ mảng a rồi tính tần suất xuất hiện của nó
bool prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void disPrime(int a[], int b[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (prime(a[i]) && a[i] > max)
        {
            max = a[i];
        }
    }
    for (int i = 0; i <= max; i++)
    {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if(prime(a[i])){
            b[a[i]]++;
        }
    }
    for (int i = 0; i <= max; i++)
    {
        if (b[i] > 0)
        {
            cout << i << " - " << b[i] << endl;
        }
    }
}
int main()
{
    nhapMang(a, n);
    distribution(a, b, n);
    cout << endl;
    disPrime(a, b, n);
}