#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int a[100], n;
    cout << "nhap n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap mang thu a[" << i << "]: ";
        cin >> a[i];
    }
    FILE *fp;                       // khai báo con trỏ tập tin đùng để khai báo tập tin
    fp = fopen("output.txt", "wt"); // Mở tập tin văn bản để ghi
    // 1.1 kiểm tra xem mở file có bị lỗi không?
    if (fp == NULL)
    {
        cout << "ERROR!" << endl;
        return -1;
    }
    // 2. Mở thành công
    fprintf(fp, "%d\n", n); // dòng đầu ghi số phần tử
    // dòng tiếp theo ghi số phần tử trong mảng mỗi phần tử có 5 chỗ
    for (int i = 0; i < n; i++)
        fprintf(fp, "%5d", a[i]);
    // đóng lại
    fclose(fp);
}