#include <iostream>
using namespace std;
int timX(int a[], int n, int x)
{
    int i = 0;
    while (i < n && a[i] != x)
        i++;
    if (i < n)
        return i;
    return -1;
}
// tìm max sử dụng sentinel
int sentX(int a[], int n)
{
    int x = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
            x = a[i];
    }
    return x;
}
void nhapXuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nhap mang a[" << i << "]: ";
        cin >> a[i];
    }
}
int sentinelFindX(int a[100], int n, int x)
{
    a[n] = x;
    int i = 0;
    while (a[i] != x)
        i++;
    if (i < n)
        return i;
    return -1;
}
// hàm kiểm tra số âm
bool ktneg(int a[], int n)
{
    a[n] = 0;
    int i = 0;
    while (a[i] != 0)
    {
        if (a[i] < 0)
        {
            return true;
        }
        i++;
    }
    return false;
}
// kiểm tra số âm cách 2
bool ktneg2(int a[], int n)
{
    a[n] = -1;
    int i = 0;
    while (a[i] >= 0)
        i++;
    return (i < n);
}
// kiểm tra full số âm
bool fullneg(int a[], int n)
{
    a[n] = 0;
    int i = 0, count = 0;
    while (a[i] != 0)
    {
        if (a[i] < 0)
        {
            count++;
        }
        i++;
    }
    if (count == n)
        return true;
    return false;
}
// fullneg2
bool fullneg2(int a[], int n)
{
    a[n] = 1;
    int i = 0;
    while (a[i] < 0)
        i++;
    return (i >= n);
}
bool ktTangDan(int a[], int n)
{
    a[n] = a[n - 1] - 1;
    int i = 0;
    while (a[i] <= a[i + 1])
        i++;
    return (i >= n);
}
int main()
{
    int a[100], n, x = 5;
    cout << "nhap n: ";
    cin >> n;
    // int kq = sentX(a, n);
    // cout << kq;
    nhapXuat(a, n);
    // int kq = sentinelFindX(a, n, x);
    // cout << kq;
    cout << ktneg2(a, n) << "\n";
    cout << fullneg2(a, n) << "\n";
    cout << ktTangDan(a, n);
}