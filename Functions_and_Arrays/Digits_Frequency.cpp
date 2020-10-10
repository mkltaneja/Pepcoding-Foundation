#include <iostream>
using namespace std;
int main()
{
    int n, d, count = 0;
    cin >> n >> d;
    while (n)
    {
        if (n % 10 == d)
            count++;
        n /= 10;
    }
    cout << count;

    return 0;
}