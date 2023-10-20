#include <iostream>
#include <fstream> // For file stream operations
using namespace std;
// 1. đọc dữ liệu từ file vào mảng 1 chiều
void readFile(const char fname[], int a[], int &n);
// 2. ghi dữ liệu từ mảng 1 chiều vào file
void writeFile(const char fname[], int a[], int n);
// 3. tách số chẵn từ mảng ban đầu vào file mới
void odd(int a[], int mc[], int n, int &nc);
int main()
{
    int a[100], mc[100], n, nc;
    readFile("input.txt", a, n);
    odd(a, mc, n, nc);
    writeFile("output.txt", mc, nc);
}
// 1. đọc dữ liệu từ file vào mảng 1 chiều
void readFile(const char fname[], int a[], int &n)
{
    // create input file stream
    ifstream fp(fname);
    if (!fp.is_open())
    {
        perror("ERROR!");
        return;
    }
    // enter the number of element
    fp >> n;
    for (int i = 0; i < n; i++)
    {
        fp >> a[i];
    }
    fp.close();
}
// 2. ghi dữ liệu từ mảng 1 chiều vào file
void writeFile(const char fname[], int a[], int n)
{
    ofstream fp(fname);
    if (!fp.is_open())
    {
        perror("ERROR!");
        return;
    }
    fp << n << "\n";
    for (int i = 0; i < n; i++)
    {
        fp << a[i] << ' ';
    }
    fp.close();
}
// 3. tách số chẵn từ mảng ban đầu vào file mới
void odd(int a[], int mc[], int n, int &nc)
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