/*We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:



Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3:



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6*/

#include <bits/stdc++.h>
using namespace std;
static bool comp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<vector<int>> task(n);
    for (int i = 0; i < n; i++)
    {
        task[i] = {startTime[i], endTime[i], profit[i]};
    }
    vector<int> dp(n);
    sort(task.begin(), task.end(), comp);
    dp[0] = task[0][2];
    for (int i = 1; i < n; i++)
    {
        int inc = task[i][2];
        int last = -1;
        int low = 0;
        int high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (task[mid][1] <= task[i][0])
            {
                last = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (last != -1)
        {
            inc += dp[last];
        }
        int exc = dp[i - 1];
        dp[i] = max(inc, exc);
    }
    return dp[n - 1];
}
int main()
{
    return 0;
}