/*swap 2 numbers without using third integer*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 5;
    int b = 3;
    a ^= b ^= a ^= b;
    cout << a << endl
         << b;
    return 0;
}