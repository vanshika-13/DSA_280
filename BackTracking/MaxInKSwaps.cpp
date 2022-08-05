/*Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5*/

#include<bits/stdc++.h>
using namespace std;
void helper(string &max,int idx,string s,int k)
    {
        if(k==0)
        {
            return;
        }
        //int m = s[idx];
        char maxc=s[idx];
        for(int i=idx+1;i<s.length();i++)
        {
            if(maxc<s[i])
            {
                maxc = s[i];
            }
        }
        if(maxc != s[idx])
        {
            k--;
        }
        for(int i=idx;i<s.length();i++)
        {
            if(s[i] == maxc)
            {
                swap(s[i],s[idx]);
                if(s.compare(max) >0)
                {
                    max = s;
                }
                helper(max,idx+1,s,k);
                swap(s[i],s[idx]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string max = str;
       helper(max,0,str,k);
       return max;
    }
int main()
{
    return 0;
}