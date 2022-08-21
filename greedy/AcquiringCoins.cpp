/*You are given a list of N coins of different denominations. You can pay an amount equivalent to any 1 coin and can acquire that coin. In addition, once you have paid for a coin, we can choose at most K more coins and can acquire those for free. The task is to find the minimum amount required to acquire all the N coins for a given value of K.

Examples :

Input : coin[] = {100, 20, 50, 10, 2, 5},
        k = 3
Output : 7

Input : coin[] = {1, 2, 5, 10, 20, 50},
        k = 3
Output : 3
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
As per the question, we can see that at a cost of 1 coin, we can acquire at most K+1 coins. Therefore, in order to acquire all the n coins, we will be choosing ceil(n/(k+1)) coins and the cost of choosing coins will be minimum if we choose the smallest ceil(n/(k+1)) ( Greedy approach). The smallest ceil(n/(k+1)) coins can be found by simply sorting all the N values in increasing order.
If we should check for time complexity (n log n) is for sorting element and (k) is for adding the total amount. So, finally Time Complexity: O(n log n). */

// C++ program to acquire all
// n coins at minimum cost
// with multiple values of k.
#include <bits/stdc++.h>
using namespace std;

// Converts coin[] to prefix sum array
void preprocess(int coin[], int n)
{
    // sort the coins value
    sort(coin, coin + n);

    // Maintain prefix sum array
    for (int i = 1; i <= n - 1; i++)
        coin[i] += coin[i - 1];
}

// Function to calculate min
// cost when we can get k extra
// coins after paying cost of one.
int minCost(int coin[], int n, int k)
{
    // calculate no. of coins needed
    int coins_needed = ceil(1.0 * n / (k + 1));

    // return sum of from prefix array
    return coin[coins_needed - 1];
}

// Driver Code
int main()
{
    int coin[] = {8, 5, 3, 10,
                  2, 1, 15, 25};
    int n = sizeof(coin) / sizeof(coin[0]);
    preprocess(coin, n);
    int k = 3;
    cout << minCost(coin, n, k) << endl;
    k = 7;
    cout << minCost(coin, n, k) << endl;
    return 0;
}
