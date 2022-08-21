#include <bits/stdc++.h>
using namespace std;
bool bfs(int node, vector<int> adj[], vector<int> color)
{
    queue<int> q;
    q.push(node);
    color[node] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto it : adj[front])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[front];
                q.push(it);
            }
            else if (color[it] == color[front])
            {
                return false;
            }
        }
    }
    return true;
}
bool checkBipartite(vector<int> adj[], int n)
{
    vector<int> color(n);
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bfs(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (checkBipartite(adj, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}