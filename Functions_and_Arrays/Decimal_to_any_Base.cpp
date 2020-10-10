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

// APPROACH 2 (without using array)
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, b, p = 1, ans = 0;
    cin >> n >> b;
    while (n)
    {
        ans += (n % b) * p;
        p *= 10;
        n /= b;
    }
    cout << ans;
    return 0;
}