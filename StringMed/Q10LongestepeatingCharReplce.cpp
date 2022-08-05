/*You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.



Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.*/

#include <bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{
    int maxi = 0, ans = 0, i = 0, j = 0;
    int n = s.size();
    unordered_map<char, int> mp;
    while (j < n)
    {
        mp[s[j]]++;
        maxi = max(maxi, mp[s[j]]);
        while ((j - i + 1) - maxi > k)
        {
            mp[s[i]]--;
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}
int main()
{
    cout << characterReplacement("ababba", 1);
    return 0;
}

/*j-i+1 actually represents the length of sliding window so basically we r first storing count of coming character. 
now we check if length of window - count of maximum occuring alphabet is greater tahn max swaps that can be performed.
while the number of charachters in sliding window - maximum occuring elemnt become less than number of swaps that can be performed than we update ans
else we keep changing element count by moving i forward*/