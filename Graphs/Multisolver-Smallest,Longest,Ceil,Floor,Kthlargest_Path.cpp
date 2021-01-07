#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void add_edge(int u, int v, int w, vector<vector<pair<int, int>>> &gp)
{
    gp[u].push_back({v, w});
    gp[v].push_back({u, w});
}

void Solutions(int src, int dest, int wsf, string path, vector<vector<pair<int, int>>> &gp, vector<bool> &vis, priority_queue<pair<int, string>> &pq)
{
    if (src == dest)
    {
        pq.push({wsf, path});
        return;
    }

    vis[src] = true;
    for (auto p : gp[src])
        if (!vis[p.first])
            Solutions(p.first, dest, wsf + p.second, path + to_string(p.first), gp, vis, pq);
    vis[src] = false;
}

string Smallest_path(priority_queue<pair<int, string>> pq)
{
    while (pq.size() != 1)
        pq.pop();

    auto top = pq.top();
    string ans = top.second + "@" + to_string(top.first);
    return ans;
}
string Largest_path(priority_queue<pair<int, string>> pq)
{
    auto top = pq.top();
    string ans = top.second + "@" + to_string(top.first);
    return ans;
}
string Just_Larger_path(priority_queue<pair<int, string>> pq, int cri)
{
    auto last = pq.top();
    while (pq.top().first > cri)
    {
        last = pq.top();
        pq.pop();
    }
    string ans = last.second + "@" + to_string(last.first);
    return ans;
}
string Just_Smaller_path(priority_queue<pair<int, string>> pq, int cri)
{
    auto top = pq.top();
    while (top.first >= cri)
    {
        pq.pop();
        top = pq.top();
    }

    if (!pq.empty())
        top = pq.top();
    // else
    //     return "";
    string ans = top.second + "@" + to_string(top.first);
    return ans;
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
    Solutions(src, dest, 0, to_string(src), gp, vis, pq);

    cout << "Smallest Path = " << Smallest_path(pq) << endl;
    cout << "Largest Path = " << Largest_path(pq) << endl;
    cout << "Just Larger Path than " << cri << " = " << Just_Larger_path(pq, cri) << endl;
    cout << "Just Smaller Path than " << cri << " = " << Just_Smaller_path(pq, cri) << endl;
    cout << k << "th largest path = " << Kth_Largest_path(pq, k) << endl;
}