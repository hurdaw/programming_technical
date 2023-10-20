#include <iostream>
#include <stdio.h>
using namespace std;
// read data from file
int main()
{
    int n, a[100], x = 0, s = 0;
    FILE *in;
    in = fopen("input.txt", "r");
    fscanf(in, "%d", &n);
    while (n != 0)
    {
        x++;
        s += n;
        fscanf(in, "%d", &n);
    }
    if (x == 0)
        cout << "\n No numbers supplies ";
    else
    {
        if (x == 1)
            cout << "\n 1 number supplies";
        else
        {
            cout<<"\n "<<x<<" number suplies";
            cout<<"\n sum of input: "<<s<<endl;
            cout<<"average of input: "<<(double)s/x<<endl;
        }
    }

    fclose(in);
}
