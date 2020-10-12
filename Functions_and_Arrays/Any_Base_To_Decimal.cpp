#include <iostream>
using namespace std;
int main()
{
    int n, b, ans = 0, p = 1;
    cin >> n >> b;
    while (n)
    {
        ans += (n % 10) * p;
        p *= b;
        n /= 10;
    }
    cout << ans;

    return 0;
}