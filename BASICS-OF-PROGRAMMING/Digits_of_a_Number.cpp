#include<iostream>
using namespace std;
int main()
{
    int n, count = -1;
    cin>>n;
    int num = n;
    while(num)
    {
        num /= 10;
        count++;
    }
    
    int div = 1;
    while(count-- > 0)
        div *= 10;
    
    while(div)
    {
        cout<<n/div<<endl;
        n %= div;
        div /= 10;
    }
    
    return 0;
}