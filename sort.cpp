#include <bits/stdc++.h>
using namespace std;
int a[100], b[100], n, m;
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
// bổ trợ cho mergsort
// trộn 2 dãy đã sắp xếp thành 1 dãy đã sắp xếp
int cmp(const void *a, const void *b)
{
    const int *x = (int *)a;
    const int *y = (int *)b;
    if (*x > *y)
        return -1;
    else if (*x < *y)
        return 1;
    return 0;
}
void q(int a[], int n)
{
    qsort(a, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void mergeArray(int a[], int n, int b[], int m)
{
    int i = 0, j = 0, count = 0, cnt[m + n];
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            cnt[count++] = a[i++];
        }
        else
        {
            cnt[count++] = b[j++];
        }
    }
    while (i < n)
    {
        cnt[count++] = a[i++];
    }
    while (j < m)
    {
        cnt[count++] = b[j++];
    }
    for (int i = 0; i < m + n; i++)
    {
        cout << cnt[i] << " ";
    }
}
void merge(int a[], int l, int m, int r)
{
    // sao chép mảng hiện thời vào vector
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] <= y[j])
        {
            a[l++] = x[i++];
        }
        else
        {
            a[l++] = y[j++];
        }
    }
    while (i < x.size())
    {
        a[l++] = x[i++];
    }
    while (j < y.size())
    {
        a[l++] = y[j++];
    }
}
void mergeSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
int paritition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    // đưa pivot về giữa
    i++;
    swap(a[i], a[r]);
    return i;
}
void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int p = paritition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}
int main()
{
    nhapMang(a, n);
    // nhapMang(b, m);
    // selectionSort(a, n);
    // cout << endl;
    // bubbleSort(a, n);
    // cout << endl;
    // insertionSort(a, n);
    // countingSort(a, cnt, n);
    // q(a, n);
    // mergeArray(a, n, b, m);
    // n=10;
    // srand(time(NULL));
    // for (int i = 0; i < n; i++)
    // {
    //     a[i] = rand() % 100;
    // }
    mergeSort(a, 0, n - 1);
    for (int i = 0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    quickSort(a, 0, n - 1);
    for (int i = 0;i<n;i++)
    {
        cout << a[i] << " ";
    }
}