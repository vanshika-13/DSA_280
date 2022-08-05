/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.*/

#include <bits/stdc++.h>
using namespace std;
int pro = 0;
vector<int> prices;
vector<vector<int>> dp;
int solve(int i, int tranNo, vector<int> &prices, vector<vector<int>> &dp, int k, int n)
{
    if (i == n || tranNo == 2 * k)
    {
        return 0;
    }
    if (dp[i][tranNo] != -1)
    {
        return dp[i][tranNo];
    }
    if (tranNo % 2 == 0)
    {
        return dp[i][tranNo] = max(-prices[i] + solve(i + 1, tranNo + 1, prices, dp, k, n), solve(i + 1, tranNo, prices, dp, k, n));
    }
    return dp[i][tranNo] = max(prices[i] + solve(i + 1, tranNo + 1, prices, dp, k, n), solve(i + 1, tranNo, prices, dp, k, n));
}
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    return solve(0, 0, prices, dp, k, n);
}
int main()
{
    return 0;
}

/*#include <bits/stdc++.h>

using namespace std;

int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp ){

    if(ind==n || cap==0) return 0; //base case
    
    if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
        
    int profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,n,ind+1,0,cap,dp), 
                    -Arr[ind] + getAns(Arr,n,ind+1,1,cap,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,n,ind+1,1,cap,dp),
                    Arr[ind] + getAns(Arr,n,ind+1,0,cap-1,dp));
    }
    
    return dp[ind][buy][cap] = profit;
}


int maximumProfit(vector<int>& prices, int n, int k)
{
    // Creating a 3d - dp of size [n][2][k+1]
    vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>> 
                                            (2,vector<int>(k+1,-1)));
    
    return getAns(prices,n,0,0,k,dp);
   
}

int main() {

  vector<int> prices = {3,3,5,0,0,3,1,4};
  int n = prices.size();
int k = 2;
                                 
  cout<<"The maximum profit that can be generated is "<<maximumProfit(prices, n,k);
}
Output:

The maximum profit that can be generated is 6

Time Complexity: O(N*2*3) 

Reason: There are N*2*K states therefore at max ‘N*2*K’ new problems will be solved.

Space Complexity: O(N*2*K) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 3D array ( O(N*2*K)).*/

/*using namespace std;


int maximumProfit(vector<int>& Arr, int n, int k)
{
    // Creating a 3d - dp of size [n+1][2][k+1] initialized to 0
    vector<vector<vector<int>>> dp(n+1,
                                    vector<vector<int>> 
                                            (2,vector<int>(k+1,0)));
                                            
    // As dp array is initialized to 0, we have already covered the base case
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=k; cap++){
                
                if(buy==0){// We can buy the stock
                    dp[ind][buy][cap] = max(0+dp[ind+1][0][cap], 
                                -Arr[ind] + dp[ind+1][1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    dp[ind][buy][cap] = max(0+dp[ind+1][1][cap],
                                Arr[ind] + dp[ind+1][0][cap-1]);
                }
            }
        }
    }
    
    
    return dp[0][0][k];
   
}

int main() {

  vector<int> prices = {3,3,5,0,0,3,1,4};
  int n = prices.size();
  int k =2;
                                 
  cout<<"The maximum profit that can be generated is "<<maximumProfit(prices, n, k);
}
Output:

The maximum profit that can be generated is 6

Time Complexity: O(N*2*k) 

Reason: There are three nested loops that account for O(N*2*K) complexity.

Space Complexity: O(N*2*k)

Reason: We are using an external array of size ‘N*2*K’. Stack Space is eliminated.*/


/*#include <bits/stdc++.h>

using namespace std;


int maxProfit(vector<int>& Arr, int n, int k)
{
    
    vector<vector<int>> ahead(2,vector<int> (k+1,0));
    
    vector<vector<int>> cur(2,vector<int> (k+1,0));
    
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=k; cap++){
                
                if(buy==0){// We can buy the stock
                    cur[buy][cap] = max(0+ahead[0][cap], 
                                -Arr[ind] + ahead[1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    cur[buy][cap] = max(0+ahead[1][cap],
                                Arr[ind] + ahead[0][cap-1]);
                }
            }
        }
        ahead = cur;
    }
    
    return ahead[0][k];
   
}

int main() {

  vector<int> prices = {3,3,5,0,0,3,1,4};
  int n = prices.size();
  int k=2;                             
  cout<<"The maximum profit that can be generated is "<<maxProfit(prices, n,k);
}
Output:

The maximum profit that can be generated is 6

Time Complexity: O(N*2*K)

Reason: There are three nested loops that account for O(N*2*K) complexity

Space Complexity: O(K)

Reason: We are using two external arrays of size ‘2*K’.*/