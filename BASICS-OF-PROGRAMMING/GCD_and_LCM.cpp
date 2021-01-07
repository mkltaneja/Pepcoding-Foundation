#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return a*b/gcd(a,b);
}

int main()
{
    int n1, n2;
    cin>>n1>>n2;
    cout<<gcd(min(n1,n2), max(n1,n2))<<endl;
    cout<<lcm(min(n1,n2), max(n1,n2));
}