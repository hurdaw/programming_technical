#include <iostream>
using namespace std;
void prefix(int a[], int b[], int n)
{
    b[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
}
void prefixSum(int n, int a[])
{
    int prefix[n + 1] = {0};
    // định nghĩa mảng prefix
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }
}
// Tìm dãy con liên tiếp có tổng lớn nhất trong một mảng số nguyên bằng cách sử dụng kỹ thuật prefix sums
int main()
{
    int a[100], n;
    cin >> n;
    for (int i = 1; i <= n; i++)    
        cin >> a[i];
    prefixSum(n, a);
}