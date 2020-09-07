#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int nsp = n/2, nst = 1, num;
    for(int i=0; i<n; i++)
    {
        if(i <= n/2)
            num = i+1;
        else
            num = n-i;
        for(int csp = 1; csp <= nsp; csp++)
            cout<<"\t";
        for(int cst = 1; cst <= nst; cst++)
        {
            cout<<num<<"\t";
            if(cst <= nst/2)
                num++;
            else
                num--;
        }
        cout<<endl;
        
        if(i < n/2)
            nsp--, nst += 2;
        else
            nsp++, nst -= 2;
    }
    return 0;
}