#include <iostream>
using namespace std;

int todecimal(int n, int b)
{
    int ans = 0, p = 1;
    while (n)
    {
        ans += (n % 10) * p;
        p *= b;
        n /= 10;
    }
    return ans;
}

int dectob2(int n, int b)
{
    int ans = 0, p = 1;
    while (n)
    {
        ans += (n % b) * p;
        p *= 10;
        n /= b;
    }
    return ans;
}

int main()
{
    int n, b1, b2;
    cin >> n >> b1 >> b2;
    int btodec = todecimal(n, b1);
    cout << dectob2(btodec, b2);

    return 0;
}