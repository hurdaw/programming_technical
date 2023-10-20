// có sử dụng quy hoạch động
#include <iostream>
#include <time.h>
using namespace std;
long long f[100];
long long fibo(int n)
{

    if (f[n] != -1) // đã được tính
    {
        return f[n];
    }
    if (n == 0)
        return f[n] = 0;
    if (n == 1 || n == 2)
        return f[n] = 1;
    return f[n] = (fibo(n - 1) + fibo(n - 2));
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        f[i] = -1;
    }
    clock_t start, end;
    start = clock();
    cout << fibo(n) << endl;
    end = clock();
    double time_used = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time_used;
}