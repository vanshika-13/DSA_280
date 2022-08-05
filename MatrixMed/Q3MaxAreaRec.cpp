/**/

#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &heights, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = heights[i];
        while (s.top() != -1 && heights[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> &heights, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = heights[i];
        while (s.top() != -1 && heights[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}
int maxArea(vector<vector<int>> &matrix)
{
    vector<int> curr;
    for (int i = 0; i < matrix[0].size(); i++)
    {
        curr.push_back(matrix[0][i]);
    }
    int maxAns = 0, currAns = 0;
    currAns = largestRectangleArea(curr);
    maxAns = currAns;
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 1)
            {
                curr[j] += 1;
            }
            else
            {
                curr[j] = 0;
            }
        }
        currAns = largestRectangleArea(curr);
        maxAns = max(maxAns, currAns);
    }
    return maxAns;
}
int main()
{
    vector<vector<int>> matrix;
    cout << maxArea(matrix);
    return 0;
}