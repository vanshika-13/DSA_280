/*You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"*/

#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s, int k)
{
    stack<pair<char, int>> st;
    st.push({s[0], 1});
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        if (!st.empty() && s[i] == st.top().first && st.top().second == (k - 1))
        {
            int t = (k - 1);
            while (t--)
            {
                st.pop();
            }
        }
        else if (!st.empty() && s[i] == st.top().first && st.top().second < (k - 1))
        {
            st.push({s[i], st.top().second + 1});
        }
        else
        {
            st.push({s[i], 1});
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans.push_back(st.top().first);
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    return 0;
}