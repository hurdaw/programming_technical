#include <iostream>
using namespace std;
void tamGiac(int n){
    for (int i = 1; i <= n; i++)
    {
        // In ra khoảng trống phía trước
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // In ra các dấu '*' ở cột phía phải
        for (int k = 1; k <= i; k++)
        {
            cout << "*";
        }

        cout << endl;
    }
}
void tamGiacDoiXung(int n){
        for (int i = 1; i <= n; i++) {
        // In ra khoảng trống phía trước
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // In ra các dấu '*' ở bên trái
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }

        // In ra các dấu '*' ở bên phải (đối xứng qua trục tung)
        for (int k = i - 1; k >= 1; k--) {
            cout << "*";
        }

        cout << endl;
    }
}
void tamGiac1(int n){
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Nhap chieu cao tam giac: ";
    cin >> n;
    tamGiac1(n);
    tamGiacDoiXung(n);
    tamGiac(n);
}
