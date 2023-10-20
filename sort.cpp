#include <bits/stdc++.h>
using namespace std;
int a[100], n;
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void nhapMang(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
// O(n^2)
// đưa giá trị nhỏ nhất chưa được sắp xếp về đầu dãy
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {

            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[min], a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
// O(n^2)
// so sánh 2 phần tử liền kề
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
// chèn vào vị trí liền trước đó nếu a[i]<a[pos]
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i], pos = i - 1;
        while (pos >= 0 && x < a[pos])
        {
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos + 1] = x;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
// counting sort O(n+(phần tử lớn nhất trong mảng))
// hạn chế:
// + Không thể dùng với mảng quá lớn
// + Khổng thể dùng với mảng có số âm
// + Phạm vi hoạt động 0<=n<=1e7
int cnt[10000000];
void countingSort(int a[], int cnt[], int &n)
{
    cin >> n;
    int m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        m = max(m, a[i]);
    }
    for (int i = 0; i <= m; i++)
    {
        if (cnt[i] != 0)
        {
            for (int j = 0; j < cnt[i]; j++)
            {
                cout << i << " ";
            }
        }
    }
}
int main()
{
    // nhapMang(a, n);
    // selectionSort(a, n);
    // cout << endl;
    // bubbleSort(a, n);
    // cout << endl;
    // insertionSort(a, n);
    countingSort(a, cnt, n);
}