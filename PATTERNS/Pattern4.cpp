#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int nsp = 0, nst = n;
    for(int i=0; i<n; i++)
    {
        for(int csp = 1; csp <= nsp; csp++)
            cout<<"\t";
        for(int cst = 1; cst <= nst; cst++)
            cout<<"*\t";
        nst--, nsp++;
        cout<<endl;
    }
    return 0;
}