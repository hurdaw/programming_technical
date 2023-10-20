#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
struct MH
{
    char maMH[100], tenMH[100];
    int stc;
    float diem;
};
typedef struct SV
{
    char mssv[100], hoten[100];
    int tuoi, so_mon;
    MH kq[100]; // mảng lưu các môn học mà sinh viên đã học
    int tongtc, tongtcq;
    float dtbc, dtbq;
} SV;
// khai báo các hàm thao tác
// 1. Đọc dữ liệu từ file --> cấu trúc SV
// Đồng thời tính các thông số còn lại (tongtc, ...)
void readFile(const char fname[], SV &s);
// 2. In thông tin của 1 sinh viên ra màn hình
void inSv(SV s);
// 3. Ghi dữ liệu từ cấu trúc SV --> file (văn bản)
void writeFile(const char fname[], SV s);
int main()
{
    SV a;
    readFile("sv.txt", a);
    inSv(a);
}
// 1. Đọc dữ liệu từ file --> cấu trúc SV
// Đồng thời tính các thông số còn lại (tongtc, ...)
void readFile(const char fname[], SV &s)
{
    // char temp[100];
    FILE *fp;
    fp = fopen(fname, "rt");
    if (!fp)
    {
        cout << "ERROR!";
        return;
    }
    fgets(s.mssv, 10, fp);
    fgets(s.hoten, 50, fp);
    fscanf(fp, "%d", &s.tuoi);
    fscanf(fp, "%d", &s.so_mon);
    fgetc(fp); // đọc ký tự xuống dòng để chuyển tới dòng tiếp theo
    fclose(fp);
}
// 2. In thông tin của 1 sinh viên ra màn hình
void inSv(SV s)
{
    cout << s.mssv << "\n";
    cout << s.hoten << "\n";
    cout << s.tuoi << "\n";
    cout << s.so_mon << "\n";
}
// 3. Ghi dữ liệu từ cấu trúc SV --> file (văn bản)
void writeFile(const char fname[], SV s[]);