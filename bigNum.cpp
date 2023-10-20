#include <iostream>
#include <conio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
// khai báo hằng
#define MAXDIGITS 100
#define PLUS 1
#define MINUS -1
typedef struct
{
    char digits[MAXDIGITS];
    int signbit;
    int lastdigit; // index of high-order digit
} bigNum;
void scan_bignum(bigNum &n);
void print_bignum(bigNum n);
int kiemTra(char s[]);
int main()
{
    do
    {
        bigNum a, b, c;
        cout << "nhap a: ";
        scan_bignum(a);
        cout << "so vua nhap la: ";
        print_bignum(a);
        cout << endl;
    } while (getch() != 27);
}
void scan_bignum(bigNum &n)
{
    // B1: nhập chuỗi
    char temp[256];
    cin.getline(temp, 256);
    // B2: Kiểm tra
    if (!kiemTra(temp)) // không hợp lệ
    {
        // gán bignum = 0;
        n.signbit = PLUS;
        n.lastdigit = 0;
        n.digits[0] = 0;
    }
    else // hợp lệ
    {
        // xét 2 trường hợp
        if (temp[0] != '-')
        {
            n.signbit = PLUS;
            n.lastdigit = strlen(temp) - 1;
            for (int i = 0; i <= n.lastdigit; i++)
                n.digits[i] = temp[n.lastdigit - i] - 48;
        }
        else
        {
            n.signbit = MINUS;
            n.lastdigit = strlen(temp) - 2;
            for (int i = 0; i <= n.lastdigit; i++)
                n.digits[i] = temp[n.lastdigit + 1 - i] - 48;
        }
    }
}
void print_bignum(bigNum n)
{
    int i;
    if (n.signbit == MINUS)
        cout << "-";
    for (i = n.lastdigit; i >= 0; i--)
        cout << int(n.digits[i]);
}   
int kiemTra(char s[])
{
    // kiểm tra kí tự đầu
    if (!isdigit(s[0]))
        return 0;
    // kiểm tra các kí tự tiếp theo
    int len = strlen(s);
    for (int i = 1; i < len; i++)
        if (!isdigit(s[i]))
            return 0;
    // không phát hiện vi phạm
    return 1;
}