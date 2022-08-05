/*Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".*/

#include <bits/stdc++.h>
using namespace std;
bool backspaceCompare(string s, string t)
{
    stack<int> s1;
    stack<int> s2;

    for (char c : s)
    {
        if (c == '#' && !s1.empty())
            s1.pop();
        else if (c == '#' && s1.empty())
            continue;
        else
            s1.push(c);
    }
    for (char c : t)
    {
        if (c == '#' && !s2.empty())
            s2.pop();
        else if (c == '#' && s2.empty())
            continue;
        else
            s2.push(c);
    }

    while (!s1.empty() && !s2.empty())
    {
        if (s1.top() != s2.top())
            return false;
        s1.pop();
        s2.pop();
    }
    if (!s1.empty() || !s2.empty())
        return false;

    return true;
}
int main()
{
    return 0;
}