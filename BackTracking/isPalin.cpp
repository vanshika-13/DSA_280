/*Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]*/

#include <bits/stdc++.h>
using namespace std;
void partition(string s)
{
    vector<vector<string>> result;
    vector<string> v;
    dfs(result, v, 0, s);
    printSolution(result);
}

void printSolution(vector<vector<string>> partitions)
{
    for (int i = 0; i < partitions.size(); ++i)
    {
        for (int j = 0; j < partitions[i].size(); ++j)
            cout << partitions[i][j] << " ";
        cout << endl;
    }
    return;
}

void dfs(vector<vector<string>> &result, vector<string> &v, int count, string s)
{
    if (count >= s.size())
    {
        result.push_back(v);
        return;
    }

    for (int i = count; i < s.size(); ++i)
    {
        if (!ispalin(count, i, s))
            continue;
        if (ispalin(count, i, s))
        {
            v.push_back(s.substr(count, i - count + 1));
            dfs(result, v, i + 1, s);
            v.pop_back();
        }
    }
}

bool ispalin(int x, int y, string z)
{

    while (x < y)
    {
        if (z[x] != z[y])
            return false;
        x++;
        y--;
    }
    return true;
}
int main()
{
    string s = "geeks";
    partition(s);
    return 0;
}