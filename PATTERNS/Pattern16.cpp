#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int nsp = 2*n-3, nst = 1;
    for(int i=0; i<n; i++)
    {
        for(int cst = 1; cst <= nst; cst++)
            cout<<cst<<"\t";
        for(int csp = 1; csp <= nsp; csp++)
            cout<<"\t";
            
        if(nst == n)
            nst--;
        for(int cst = 1; cst <= nst; cst++)
            cout<<nst-cst+1<<"\t";
        cout<<endl;
        
        nsp -= 2, nst++;
    }
    return 0;
}