#include <iostream>
#include <vector>
using namespace std;

void add_edge(int u, int v, int w, vector<vector<pair<int, int>>> &gp)
{
    gp[u].push_back({v, w});
    gp[v].push_back({u, w});
}

bool has_path(int src, int dest, int n, vector<vector<pair<int, int>>> &gp, vector<bool> &vis)
{
    if (src == dest)
        return true;
    vis[src] = true;

    bool res = false;
    for (auto p : gp[src])
        if (!vis[p.first] && !res)
            res |= has_path(p.first, dest, n, gp, vis);
    return res;
}

int main()
{
    int n, edges, src, dest;
    cin >> n >> edges;
    vector<vector<pair<int, int>>> gp(n);
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w, gp);
    }
    cin >> src >> dest;

    vector<bool> vis(n, false);
    cout << (boolalpha) << has_path(src, dest, n, gp, vis);
}