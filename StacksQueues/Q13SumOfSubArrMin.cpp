/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444*/

#include <bits/stdc++.h>
using namespace std;
int sumSubarrayMins(vector<int> &arr)
{
    stack<int> s;
    vector<int> v;
    int n = arr.size();
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else
        {

            while (s.size() > 0 && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(i);
    }
    // reverse(v.begin(),v.end());
    vector<int> h;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            h.push_back(n);
        }
        else
        {

            while (st.size() > 0 && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                h.push_back(n);
            }
            else
            {
                h.push_back(st.top());
            }
        }
        st.push(i);
    }
    reverse(h.begin(), h.end());
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // cout<<h[i]<<" " << v[i] << " " << arr[i] <<endl;
        long long int x = h[i] - i;
        long long int y = i - v[i];
        // cout<<x<<" " << y<<endl;
        ans = (ans % mod + ((x * y) * arr[i]) % mod) % mod;
    }
    return ans % mod;
}
int main()
{
    return 0;
}