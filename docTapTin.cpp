#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int a[100], n;
    FILE *fp;                       // khai báo con trỏ tập tin đùng để khai báo tập tin
    fp = fopen("output.txt", "rt"); // Mở tập tin văn bản để ghi
    // 1.1 kiểm tra xem mở file có bị lỗi không?
    if (fp == NULL)
    {
        cout << "ERROR!" << endl;
        return -1;
    }
    // 2. Mở thành công
    fscanf(fp, "%d", &n); // dòng đầu ghi số phần tử
    // dòng tiếp theo ghi số phần tử trong mảng mỗi phần tử có 5 chỗ
    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);
    // đóng lại
    fclose(fp);
    // xuất ra màn hình mảng vừa đọc được
    cout << "mang vua nhap duoc la: \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}