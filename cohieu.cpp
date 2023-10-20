#include <iostream>
using namespace std;
void nhapXuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nhap mang a[" << i << "]: ";
        cin >> a[i];
    }
}
// tìm kiếm tuần tự
int Lsearch(int a[], int n, int x)
{
    int i = 0;    // xuất phát từ đầu mảng
    int cont = 1; // có tìm kiếm hay không
    while (i < n && cont)
    {
        if (a[i] == 0)
            cont = 0;
        else
            i++;
    }
    if (i < n)
        return i;
    return -1;
}
// xóa phần tử tại vị trí k trong mảng
void deleteK(int a[], int &n, int k)
{
    if (k < 0 || k >= n) // k không hợp lệ
        return;
    for (int i = k + 1; i < n; i++)
        a[i - 1] = a[i]; // dồn k lên
    n--;                 // giảm số lượng phần tử
}
// xóa trùng
void xoaTrung(int a[], int &n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool trung = false;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] == a[i])
            {
                trung = true;
                deleteK(a, n, j--);
            }
        }
        if (trung)
            deleteK(a, n, i--);
    }
}
int main()
{
    int a[100], n, k = 2;
    cout << "nhap n: ";
    cin >> n;
    nhapXuat(a, n);
    xoaTrung(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}