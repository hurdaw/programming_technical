#include <iostream>
using namespace std;
// Tính tổng của một mảng số nguyên sử dụng kỹ thuật prefix sums
int main()
{
    int n, a[100];
    cout << "nhap so luong phan tu mang: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
    int prefix[n];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            prefix[0] = a[0];
        }
        else
        {
            prefix[i] = prefix[i - 1] + a[i];
        }
    }
    cout << "tong cua mang la: " << prefix[n-1] << endl;
}