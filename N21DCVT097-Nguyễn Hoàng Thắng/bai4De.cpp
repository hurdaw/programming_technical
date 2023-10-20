#include <iostream>
using namespace std;
// Tính giai thừa của một số nguyên dương bằng cách sử dụng đệ quy.Bài tập trung bình
int giaithua(int n)
{
    if (n == 1)
        return 1;
    return (n * giaithua(n - 1));
}
int main()
{
    int n;
    do
    {
        cin>>n;
    } while (n<=0);
    cout<<giaithua(n);
}