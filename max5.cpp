#include <iostream>
using namespace std;

int main()
{
    int a[5];
    int max = 0;
    for(int i=0;i<5;i++){
            cin>>a[i];
            if(a[i]>max)    max=a[i];
    }
    cout<<max;
    
}