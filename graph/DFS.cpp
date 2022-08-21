#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
    {
        vis[node] = 1;
        ans.push_back(node);
        for (auto padosi : adj[node])
        {
            if (!vis[padosi])
            {
                dfs(padosi, adj, vis, ans);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> ans;
        dfs(0, adj, vis, ans);
        return ans;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> adj[5];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}