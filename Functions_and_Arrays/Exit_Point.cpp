#include <iostream>
#include <vector>
using namespace std;

void exit_point(int n, int m, vector<vector<int>> &arr)
{
    int i = 0, j = 0;
    int d = 0;
    bool flag = true;

    while (flag)
    {
        // cout<<d<<endl;
        if (d == 0)
        {
            // cout<<d<<": \n";
            while (arr[i][j] == 0)
            {
                j++;
                // cout<<i<<", "<<j<<" --> ";
                if (j == m)
                {
                    cout << i << ", " << j - 1;
                    flag = false;
                    break;
                }
            }
            i++;
        }
        else if (d == 1)
        {
            // cout<<d<<": \n";
            while (arr[i][j] == 0)
            {
                i++;
                // cout<<i<<", "<<j<<" --> ";
                if (i == n)
                {
                    cout << i - 1 << ", " << j;
                    flag = false;
                    break;
                }
            }
            j--;
        }
        else if (d == 2)
        {
            // cout<<d<<": \n";
            while (arr[i][j] == 0)
            {
                j--;
                // cout<<i<<", "<<j<<" --> ";
                if (j == -1)
                {
                    cout << i << ", " << j + 1;
                    flag = false;
                    break;
                }
            }
            i--;
        }
        else if (d == 3)
        {
            // cout<<d<<": \n";
            while (arr[i][j] == 0)
            {
                i--;
                // cout<<i<<", "<<j<<" --> ";
                if (i == -1)
                {
                    cout << i + 1 << ", " << j;
                    flag = false;
                    break;
                }
            }
            j++;
        }
        d = (d + 1) % 4;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    exit_point(n, m, arr);
}