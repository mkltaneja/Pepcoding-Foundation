
// METHOD 1 (Using strings)
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s = to_string(n);
    int sz = s.size();
    int i = 1;
    while(n)
    {
        int l = n % 10;
        s[sz-(l-1)-1] = (char)(i++ + '0');
        n /= 10;
    }
    cout<<s;
    
    return 0;
}

///////////////////////////////OR/////////////////////////

// METHOD 2 (Using number)
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
    int n;
    cin>>n;
    int i = 1;
    int inv = 0;
    while(n)
    {
        int l = n % 10;
        int pos = pow(10,l-1);
        pos *= i++;
        inv += pos;
        n /= 10;
    }
    cout<<inv;
    
    return 0;
}