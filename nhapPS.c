#include <stdio.h>
struct phanSo
{
    int ts, ms;
};
typedef struct phanSo PS;
// khai bao ham
// 1. nhap 1 phan so
void nhapPS(PS *a)
{
    printf("nhap tu so ");
    scanf("%d", &a->ts);
    do
    {
        printf("nhap mau so (khac 0) ");
        scanf("%d", &a->ms);
    } while (a->ms == 0);
}
// 2. nhap mang gom n phan so
void nhapMang(PS a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        nhapPS(&a[i]);
    }
}
void inPhanSo(PS a[], int n)
{
    printf("in ra man hinh phan so da nhap: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d/%d ", a[i].ts, a[i].ms);
    }
}
// 3. tim phan so co gia tri thuc cua 1 phan so
float value(PS a)
{
    return (float)a.ts / a.ms;
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
    printf("nhap so luong phan so: ");
    scanf("%d", &n);
    nhapMang(m, n);
    inPhanSo(m, n);
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", value(m[i]));
    }
}