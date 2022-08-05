/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.



Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]*/

#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> s;
    vector<int> ans;
    int n = temperatures.size();
    for (int i = (n - 1); i >= 0; i--)
    {
        while (!s.empty() && temperatures[i] >= temperatures[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans.push_back(0);
            s.push(i);
        }
        else
        {
            ans.push_back(s.top() - i);
        }
        s.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    return 0;
}