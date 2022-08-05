/*Given a 3 x n board, find the number of ways to fill it with 2 x 1 dominoes.
Example 1
Following are all the 3 possible ways to fill up a 3 x 2 board.




Example 2
Here is one possible way of filling a 3 x 8 board. You have to find all the possible ways to do so.




Examples :


Input : 2
Output : 3

Input : 8
Output : 153

Input : 12
Output : 2131*/

// C++ program to find no. of ways
// to fill a 3xn board with 2x1 dominoes.
#include <iostream>
using namespace std;

int countWays(int n)
{
    int A[n + 1], B[n + 1];
    A[0] = 1, A[1] = 0, B[0] = 0, B[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        A[i] = A[i - 2] + 2 * B[i - 1];
        B[i] = A[i - 1] + B[i - 2];
    }

    return A[n];
}

int main()
{
    int n = 8;
    cout << countWays(n);
    return 0;
}
