// // #include <stdio.h>
// #include <iostream>
// #include <fstream>
// using namespace std;
// // đọc vào file nhị phân
// void readFile(const char fname[], int a[], int n);
// // ghi vào file nhị phân
// void writeFile(const char fname[], int a[], int n);
// int main()
// {
//     int a[100] = {1, 3, 5, 6, 7}, n = 5, b[100], nb;
//     // ghi mảng a lên tập tin
//     writeFile("vd1.bin", a, n);
// }
// void read(char fname[], int a[], int n)
// {
//     FILE *fp;
//     fp = fopen(fname, "rb");
//     if (fp == NULL)
//     {
//         cout << "ERROR!";
//         return;
//     }
//     // fscanf(fp, "%d", &n);   //đọc số lượng phần tử trong mảng
//     fread(&fp, sizeof(int), 1, fp); // đọc 1 phần tử
//     // for (int i = 0; i < n; i++)
//     // {
//     //     fscanf(fp, "%d", &n);
//     // }
//     fread(a, sizeof(int), n, fp); // đọc toàn bộ mảng lưu vào a

//     fclose(fp);
// }
// void write(char fname[], int a[], int n)
// {
//     FILE *fp;
//     fp = fopen(fname, "wb");
//     if (fp == NULL)
//     {
//         cout << "ERROR!";
//         return;
//     }
//     // fscanf(fp, "%d", &n);   //đọc số lượng phần tử trong mảng
//     fwrite(&fp, sizeof(int), 1, fp); // đọc 1 phần tử
//     // for (int i = 0; i < n; i++)
//     // {
//     //     fscanf(fp, "%d", &n);
//     // }
//     fwrite(a, sizeof(int), n, fp); // đọc toàn bộ mảng lưu vào a

//     fclose(fp);
// }

#include <iostream>
#include <fstream>
using namespace std;
// read file bin into array
void readBin(const char fname[], int a[], int &n);
// write from array to file
void writeBin(const char fname[], int a[], int n);
int main()
{
    int a[100], n;
    readBin("input.bin", a, n);
    writeBin("output.bin", a, n);
}
// read file bin into array
void readBin(const char fname[], int a[], int &n)
{
    // check if open succeed
    ifstream fp(fname, ios::binary);
    if (!fp.is_open())
    {
        perror("ERROR!");
        return;
    }
    fp.read(reinterpret_cast<char *>(&n), sizeof(n));
    fp.read(reinterpret_cast<char *>(a), n * sizeof(int));
    fp.close();
}
// write from array to file
void writeBin(const char fname[], int a[], int n)
{
    // check if open succeed
    ofstream fp(fname, ios::binary);
    if (!fp.is_open())
    {
        perror("ERROR!");
        return;
    }
    fp.write(reinterpret_cast<char *>(&n), sizeof(n));
    fp.write(reinterpret_cast<char *>(a), n * sizeof(int));
    fp.close();
}