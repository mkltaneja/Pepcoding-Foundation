#include <iostream>
#include <vector>
using namespace std;

void add_edge(int u, int v, int w, vector<vector<pair<int, int>>> &gp)
{
    gp[u].push_back({v, w});
    gp[v].push_back({u, w});
}

void all_path(int src, int dest, int n, vector<vector<pair<int, int>>> &gp, vector<bool> &vis, string path)
{
    path += to_string(src);
    if (src == dest)
    {
        cout << path << endl;
        return;
    }

    vis[src] = true;

    for (auto p : gp[src])
        if (!vis[p.first])
            all_path(p.first, dest, n, gp, vis, path);

    vis[src] = false;
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
    all_path(src, dest, n, gp, vis, "");
}