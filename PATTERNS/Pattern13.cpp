
// METHOD 1 (Using array)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,1));
    for(int i = 2; i < n; i++)
    {
        for(int j = 1; j < i; j++)
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            cout<<arr[i][j]<<"\t";
        cout<<endl;
    }
    
    return 0;
}

/////////////////////////////////////////////OR///////////////////////////////

// METHOD 2 (Without array --> using nCr Formula)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int iCj = 1;
        for(int j = 0; j <= i; j++)
        {
            cout<<iCj<<"\t";
            iCj = iCj* (i-j)/(j+1);
        }
        cout<<endl;
    }
    
    return 0;
}