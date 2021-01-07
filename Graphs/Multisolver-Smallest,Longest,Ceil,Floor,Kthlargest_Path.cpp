#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void add_edge(int u, int v, int w, vector<vector<pair<int, int>>> &gp)
{
    gp[u].push_back({v, w});
    gp[v].push_back({u, w});
}

int mini = INT_MAX;
int maxi = INT_MIN;
int smaller = INT_MIN;
int larger = INT_MAX;
string minpath = "";
string maxpath = "";
string smallerpath = "";
string largerpath = "";

void Solutions(int src, int dest, int wsf, string path, vector<vector<pair<int, int>>> &gp, vector<bool> &vis, priority_queue<pair<int, string>> &pq, int cri, int k)
{
    if (src == dest)
    {
        pq.push({wsf, path});
        if (wsf < mini)
        {
            mini = wsf;
            minpath = path;
        }
        if (wsf > maxi)
        {
            maxi = wsf;
            maxpath = path;
        }
        if (wsf < cri && wsf > smaller)
        {
            smaller = wsf;
            smallerpath = path;
        }
        if (wsf > cri && wsf < larger)
        {
            larger = wsf;
            largerpath = path;
        }
        return;
    }

    vis[src] = true;
    for (auto p : gp[src])
        if (!vis[p.first])
            Solutions(p.first, dest, wsf + p.second, path + to_string(p.first), gp, vis, pq, cri, k);
    vis[src] = false;
}

string Kth_Largest_path(priority_queue<pair<int, string>> pq, int k)
{
    while (--k)
        pq.pop();

    auto top = pq.top();
    string ans = top.second + "@" + to_string(top.first);
    return ans;
}

int main()
{
    int n, edges, src, dest, cri, k;
    cin >> n >> edges;
    vector<vector<pair<int, int>>> gp(n);
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w, gp);
    }
    cin >> src >> dest >> cri >> k;

    priority_queue<pair<int, string>> pq;
    vector<bool> vis(n, false);
    Solutions(src, dest, 0, to_string(src), gp, vis, pq, cri, k);

    cout << "Smallest Path = " << minpath << "@" << mini << endl;
    cout << "Largest Path = " << maxpath << "@" << maxi << endl;
    cout << "Just Larger Path than " << cri << " = " << largerpath << "@" << larger << endl;
    cout << "Just Smaller Path than " << cri << " = " << smallerpath << "@" << smaller << endl;
    cout << k << "th largest path = " << Kth_Largest_path(pq, k) << endl;
}