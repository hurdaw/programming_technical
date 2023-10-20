#include <iostream>
using namespace std;
// Viết một chương trình sử dụng vòng lặp để in ra các số từ 1 đến 10
void baide()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << i << " ";
    }
}
// tổng các số từ 1 đến n bằng cách sử dụng vòng lặp
int baiTrungBinh(int &n)
{
    int sum = 0;
    cout << "\nnhap n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}
// Viết một chương trình để tạo dãy Fibonacci đến một số n bằng cách sử dụng vòng lặp.
int baiKho(int n)
{
    int a = 0, b = 1, fibo;
    for (int i = 1; i <= n; i++)
    {
        fibo = a + b;
        b = a;
        a = fibo;
    }
    return fibo;
}
int main()
{
    int n;

    baide();
    int tong = baiTrungBinh(n);
    cout << tong;
    cout << "\nnhap n so Fibonacci: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << baiKho(i) << " ";
    }
}