#include <iostream>
#include <vector>
using namespace std;

void spiral_print(int n, int m, vector<vector<int>> &arr)
{
    int sr = 0, sc = 0, er = n - 1, ec = m - 1;
    int count = 0;
    int d = 0;
    while (count < n * m)
    {
        if (d == 0)
        {
            int i = sr, j = sc;
            while (i <= er)
            {
                cout << arr[i++][j] << endl;
                count++;
            }
            sc++;
        }
        else if (d == 1)
        {
            int i = er, j = sc;
            while (j <= ec)
            {
                cout << arr[i][j++] << endl;
                count++;
            }
            er--;
        }
        else if (d == 2)
        {
            int i = er, j = ec;
            while (i >= sr)
            {
                cout << arr[i--][j] << endl;
                count++;
            }
            ec--;
        }
        else if (d == 3)
        {
            int i = sr, j = ec;
            while (j >= sc)
            {
                cout << arr[i][j--] << endl;
                count++;
            }
            j++;
            sr++;
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
    spiral_print(n, m, arr);
}