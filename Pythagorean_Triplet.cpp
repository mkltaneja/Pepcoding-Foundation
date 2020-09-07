#include<iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    int maxi = max(a, max(b, c));
    if(a*a + b*b == maxi*maxi || b*b + c*c == maxi*maxi || a*a + c*c == maxi*maxi)
        cout<<"true";
    else
        cout<<"false";
        
    return 0;
}