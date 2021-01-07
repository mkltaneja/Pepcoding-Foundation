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
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        isprime(n) ? cout<<"prime" : cout<<"not prime";
        cout<<endl;
    }
    return 0;
}