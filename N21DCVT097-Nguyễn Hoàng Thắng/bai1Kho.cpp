#include <iostream>
using namespace std;
// Viết một chương trình để tạo dãy Fibonacci đến một số n bằng cách sử dụng vòng lặp.
int main()
{
    int n;
    cout << "nhap n so Fibonacci: ";
    cin >> n;
    int a = 0, b = 1, fibo;
    for (int i = 1; i <= n; i++)
    {
        fibo = a + b;
        b = a;
        a = fibo;
        cout << fibo << " ";
    }
}