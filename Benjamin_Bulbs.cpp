
// METHOD 1 (USING PRIME SEIVE)
// TLE --> O(2*n)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> bulbs(n+1,0);
    for(int i = 1; i<= n; i++)
        for(int j = i; j <= n; j += i)
            bulbs[j] ^= 1;
    for(int i = 1; i <= n; i++)
        if(bulbs[i] == 1)
            cout<<i<<endl;
    return 0;
} 

// Method 2 (using observation --> every perfect square is the ans)
// AC --> O(sqrt(n))
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i*i <= n; i++)
        cout<<i*i<<endl;
    return 0;
}