#include <iostream>
using namespace std;
typedef struct PS
{
    int ts, ms;
} PS;
// 1. nhap 1 phan so
void nhapPS(PS &a)
{
    cout << "nhap tu so: " << endl;
    cin >> a.ts;
    do
    {
        cout << "nhap mau so (khac 0): " << endl;
        cin >> a.ms;
    } while (a.ms == 0);
}
// 2. nhap 1 mang phan so
void nhapMangPS(PS a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        nhapPS(a[i]);
    }
}
// 3. tim phan so co gia tri thuc cua 1 phan so
float value(PS a)
{
    return float(a.ts) / a.ms;
}
// 4. tim phan so co gia tri thuc lon nhan trong mang
PS timMax(PS a[], int n)
{
    PS max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (value(max) < value(a[i]))
        {
            max = a[i];
        }
    }
    return max;
}
int main()
{
    PS m[100];
    int n;
    cout << "nhap so luong phan so: ";
    cin >> n;
    nhapMangPS(m, n);
    // khai bao bien hung de nhan kq tu ham timMax
    PS kq = timMax(m, n);
    cout << "phan so lon nhan: " << kq.ts << "/" << kq.ms << endl;
}