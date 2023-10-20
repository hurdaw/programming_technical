#include <iostream>
using namespace std;
// tổng các số từ 1 đến n bằng cách sử dụng vòng lặp
int main()
{
    int sum = 0, n;
    cout << "nhap n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << sum;
}