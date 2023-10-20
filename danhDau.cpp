#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[n];
    cin >> n;
    for (int &x : a)
    {
        cin >> x;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum += a[i];
        }
        cout << sum << endl;
    }
}