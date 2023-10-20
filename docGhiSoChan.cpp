#include <iostream>
#include <stdio.h>
using namespace std;
// 1. đọc dữ liệu từ file và lưu vào mảng 1 chiều các số nguyên
void readFile(const char fname[], int a[], int &n);
// 2. ghi dữ liệu từ file
void writeFile(const char fname[], int a[], int n);
// 3. tạo mảng gồm các số chẵn lấy từ mảng ban đầu
void odd(int a[], int n, int mc[], int &nc);
int main()
{
    int a[100], mc[100], n, nc;
    readFile("input.txt", a, n);
    odd(a, n, mc, nc);
    writeFile("output.txt", mc, nc);
}
// 1. đọc dữ liệu từ file và lưu vào mảng 1 chiều các số nguyên
void readFile(char fname[], int a[], int &n)
{
    FILE *fp; // khai báo con trỏ tập tin
    // open
    fp = fopen(fname, "rt");
    // mở không được thì báo lỗi
    if (fp == NULL)
    {
        cout << "ERROR!";
        return;
    }
    fscanf(fp, "%d", &n); // nhập số phần tử
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }
    // đóng file
    fclose(fp);
}
// 2. ghi dữ liệu từ mảng 1 chiều sang tập tin văn bản
void writeFile(char fname[], int a[], int n)
{
    FILE *fp; // khai báo con trỏ tập tin
    // open
    fp = fopen(fname, "wt");
    // mở không được thì báo lỗi
    if (fp == NULL)
    {
        cout << "ERROR!";
        return;
    }
    fprintf(fp, "%d\n", n); // nhập số phần tử
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%5d", a[i]);
    }
    // đóng file
    fclose(fp);
}
// 3. tạo mảng gồm các số chẵn lấy từ mảng ban đầu
void odd(int a[], int n, int mc[], int &nc)
{
    nc = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            mc[nc] = a[i];
            nc++;
        }
    }
}