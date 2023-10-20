#include <iostream>
#include <fstream>
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
void readFile(const char fname[], SV s[], int &n);
// 2. In thông tin của 1 sinh viên ra màn hình
void inSv(SV s);
// 3. Ghi dữ liệu từ cấu trúc SV --> file (văn bản)
void writeFile(const char fname[], SV s[], int n);
int main()
{
    SV a[100];
    int n;
    readFile("sv.txt", a);
    for (int i = 0; i < n; i++)
    {
        inSv(a[i]);
    }
    writeFile("struct_student_output.txt", a);
}
// 1. Đọc dữ liệu từ file --> cấu trúc SV
// Đồng thời tính các thông số còn lại (tongtc, ...)
void readFile(const char fname[], SV s[])
{
    // 1. create input stream
    ifstream fp;
    fp.open("sv.txt", ios_base::in);
    if (!fp.is_open())
    {
        perror("ERROR!");
        return;
    }
    while (fp.eof() != true)
    {
        fp >> s[n++];
    }
}
// 2. In thông tin của 1 sinh viên ra màn hình
void inSv(SV s)
{
    cout << s.mssv << "\n";
    cout << s.hoten << "\n";
    cout << s.tuoi << "\n";
    cout << s.so_mon << "\n";
}
// 3. Ghi dữ liệu từ cấu trúc SV-- > file(văn bản)
void writeFile(const char fname[], SV s[], int n)
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
        fp << s[i].mssv << ' ' << s[i].hoten << ' ' << s[i].tuoi << ' ' << s[i].so_mon << '\n';
    }
    fp.close();
}
