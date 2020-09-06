#include<iostream>
using namespace std;

int pow(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int n, k;
    cin>>n>>k;
    
    int count = 0, nn = n;
    while(nn)
    {
        count++;
        nn /= 10;
    }
    k = k % count;
    if(k < 0)
        k += count;
    
    int cut = pow(10, K);
    int shifted = n % cut;
    n /= cut;
    shifted *= pow(10, (count-K));
    n += shifted;
    
    cout<<n;
    
    return 0;
}