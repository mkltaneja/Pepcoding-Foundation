#include<iostream>
using namespace std;

bool isprime(int n)
{
    for(int i=2; i*i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main()
{
    int l,h;
    cin>>l>>h;
    for(; l <= h; l++)
    {
        if(isprime(l))
            cout<<l<<endl;
    }
    return 0;
}