#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto padosi : adj[node])
            {
                if (!vis[padosi])
                {
                    vis[padosi] = 1;
                    q.push(padosi);
                }
            }
        }
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
    vector<int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}