#include <iostream>
using namespace std;

int main()
{
    int a[100], n, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    cout << max;
}