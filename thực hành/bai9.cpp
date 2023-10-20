#include <iostream>
using namespace std;

int main()
{
    int a[100][100], m, n;
    cout << "nhap so dong: ";
    cin >> m;
    cout << "nhap so cot: ";
    cin >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    
}