#include <iostream>
#include <conio.h>
using namespace std;
// putchar(): để hiển thị ra màn hình kí tự vừa nhập
// gets():
int main()
{
    cout << "nhap x: ";
    char x;
    // getchar(): nhập 1 kí tự từ bàn phím phải enter mới nhận
    // x=getchar();
    // putchar(x);
    // getche(): nhập ngay khi nhấn phím không cần enter
    // x=getche();
    // putchar(x);
    // getch(): y như getche() nhưng không hiển thị kí tự nhập vào, muốn hiển thị thì dùng cout<<
    // x =getch();
    // putchar(x);
    // gets(): nhập 1 chuỗi kí tự lấy luôn cả dấu cách
    char s[100];
    gets(s);
    puts(s);    // hiển thị chuỗi kí tự vừa nhập
}