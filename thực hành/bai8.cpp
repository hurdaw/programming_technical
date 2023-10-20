#include <iostream>
using namespace std;
void tangDan(int a[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                int tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
        cout << a[i] << " ";
    }
}
int main()
{
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    tangDan(a, n);
}