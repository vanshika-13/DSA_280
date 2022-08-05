/**/

#include <bits/stdc++.h>
using namespace std;
static bool isSafeToPlaceColor(int node, vector<int> &color, bool graph[101][101], int colour)
{

    for (int i = 0; i < color.size(); i++)
    {
        if (graph[node][i])
        {
            if (color[i] == colour)
                return false;
        }
    }

    return true;
}

bool isItPossibleToColorTheGraph(int node, vector<int> &color, bool graph[101][101], int m, int n)
{
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isSafeToPlaceColor(node, color, graph, i))
        {
            color[node] = i;

            if (isItPossibleToColorTheGraph(node + 1, color, graph, m, n))
                return true;

            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // Your code here

    vector<int> color(n, 0);

    return (isItPossibleToColorTheGraph(0, color, graph, m, n));
}
int main()
{
    return 0;
}