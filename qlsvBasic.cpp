#include <iostream>
using namespace std;
// quản lý sinh viên xem sinh viên đó đậu bao nhiêu môn và chiếm bao nhiêu phần trăm tổng số môn
// struct sinhVien
// {
//     char hoTen[100];
//     int soMon;
//     float d[100];
//     float dtb;
// };
// typedef struct sinhVien SV;
typedef struct SV
{
    char hoTen[100];
    int soMon;
    float d[100];
    float dtb;
} SV;
// 1. nhập thông tin sinh viên
float tinhdtb(SV a);
void nhapSV(SV &a)
{
    cout << "nhap ten sinh vien: ";
    cin.getline(a.hoTen, 100);
    cout << "nhap so mon: ";
    cin >> a.soMon;
    for (int i = 0; i < a.soMon; i++)
    {
        cout << "nhap diem mon thu " << i << ": ";
        cin >> a.d[i];
    }
    // Tính điểm trung bình
    a.dtb = tinhdtb(a);
}
// 2. Tính điểm trung bình
float tinhdtb(SV a)
{
    float dtb = 0;
    if (a.soMon == 0)
        return 0;
    for (int i = 0; i < a.soMon; i++)
    {
        dtb += a.d[i];
    }
    return dtb / a.soMon;
}
// 3. Kiểm tra sinh vien đó đậu bao nhiêu môn
int soMonPassed(SV a)
{
    int count = 0;
    for (int i = 0; i < a.soMon; i++)
    {
        if (a.d[i] >= 4)
        {
            count++;
        }
    }
    return count;
}
// 4. xác định phần trăm đậu
float phanTramPassed(SV a)
{
    float phanTram = ((float)soMonPassed(a) / a.soMon) * 100;
    return phanTram;
}
// nhập mảng không trùng
void nhapMangkhongtrung(int b[], int m)
{
    int trung;
    for (int i = 0; i < m; i++)
    {
        do
        {
            trung = 0;
            cout << "b[" << i << "]= ";
            cin >> b[i];
            for (int j = 0; j < i; j++)
            {
                if (b[i] == b[j])
                {
                    trung = 1;
                    break;
                }
            }
        } while (trung);
    }
}
int main()
{
    SV a;
    // int b[100], m;
    // cin >> m;
    nhapSV(a);
    cout << "so diem trung binh la: " << a.dtb << endl;
    cout << "so mon da qua: " << soMonPassed(a) << endl;
    cout << "phan tram mon passed: " << phanTramPassed(a) << "%" << endl;
    // nhapMangkhongtrung(b, m);
}