#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, b;
    cin >> n >> b;
    vector<int> rem;
    while (n)
    {
        rem.push_back(n % b);
        n /= b;
    }
    int ans = 0;
    for (int i = rem.size() - 1; i >= 0; i--)
    {
        ans *= 10;
        ans += rem[i];
    }
    cout << ans;

    return 0;
}