#include <bits/stdc++.h>
using namespace std;
// nhập mssv, điểm rồi sắp xếp theo counting Sort.
// dùng linear tìm tất cả phân tử trong mảng.
// dùng binary search tìm phần tử bất kỳ trong mảng
int a[100], n;
typedef struct sinhVien
{
    int mssv[10];
    int score[100];
    int numberOfStudent;
} sv;
void nhapSv(sv &a)
{
    cout << "nhap so luong sinh vien: ";
    cin >> a.numberOfStudent;
    for (int i = 0; i < a.numberOfStudent; i++)
    {
        cout << "nhap mssv: ";
        cin >> a.mssv[i];
        cout << "nhap diem: ";
        cin >> a.score[i];
    }
}
void countingSort(sv a[], int n)
{
    int maxScore = 0;
    for (int i = 0; i < n; i++)
    {
    }
}
void nhapMang(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int binarySearch(int a[], int &x)
{
    cout << "nhap so can tim: ";
    cin >> x;
    int n = sizeof(*a) / sizeof(a[0]);
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;
        if (x < a[mid])
            right = mid - 1;
        left = mid + 1;
    }
}
int linear1Element(int a[], int n, int &x)
{
    cout << "nhap so can tim: ";
    cin >> x;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            index = i;
        }
    }
    return index;
}
int main()
{
    int x;
    sv a;
    // nhapMang(a, n);
    // int kq2 = binarySearch(a, x);
    // cout << "so can tim o vi tri: " << kq2 << endl;
    //  int kq1 = linear1Element(a, n, x);
    //  cout << "so can tim o vi tri: " << kq1 << endl;
    nhapSv(a);
}