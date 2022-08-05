/*count number of set bits in  a binary number*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a = 3;
    int count = 0;
    while (a)
    {
        a = a & (a - 1);
        count++;
    }
    cout<<count<<endl;
    return 0;
}