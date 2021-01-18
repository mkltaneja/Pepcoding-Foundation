#include <iostream>
#include <vector>
#define f first
#define s second
using namespace std;

void add_edge(int u, int v, int w, vector<vector<pair<int, int>>> &gp)
{
    gp[u].push_back({v, w});
    gp[v].push_back({u, w});
}

int cnt = 0;
void gcc(int src, int n, vector<vector<int>> &comps, vector<bool> &vis, vector<vector<pair<int, int>>> &gp)
{
    vis[src] = true;
    comps[cnt].push_back(src);
    for (auto p : gp[src])
        if (!vis[p.f])
            gcc(p.f, n, comps, vis, gp);
}

void display(vector<vector<int>> &comps)
{
    cout << "[";
    for (int i = 0; i < cnt; i++)
    {
        cout << "[";
        for (int j = 0; j < comps[i].size() - 1; j++)
            cout << comps[i][j] << ", ";
        cout << comps[i][comps[i].size() - 1] << "]";
        if (i != cnt - 1)
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> gp(n);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w, gp);
    }

    vector<vector<int>> comps(n);
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            gcc(i, n, comps, vis, gp);
            cnt++;
        }
    }

    display(comps);
}