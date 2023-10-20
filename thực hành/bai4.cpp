#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n * factorial(n - 1));
    }
}
int main()
{
    int n, tich = 1;
    do
    {
        cin >> n;
    } while (n < 0);
    cout << factorial(n);
}