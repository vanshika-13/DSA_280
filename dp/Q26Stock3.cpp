/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.*/

#include <bits/stdc++.h>
using namespace std;
int solve(int i, int tranNo, vector<int> &prices, vector<vector<int>> &dp, int n)
{
    if (i == n || tranNo == 4)
    {
        return 0;
    }
    if (dp[i][tranNo] != -1)
    {
        return dp[i][tranNo];
    }
    if (tranNo % 2 == 0)
    {
        return dp[i][tranNo] = max(-prices[i] + solve(i + 1, tranNo + 1, prices, dp, n), solve(i + 1, tranNo, prices, dp, n));
    }
    return dp[i][tranNo] = max(prices[i] + solve(i + 1, tranNo + 1, prices, dp, n), solve(i + 1, tranNo, prices, dp, n));
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(0, 0, prices, dp, n);
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


int maxProfit(vector<int>& prices, int n)
{
    // Creating a 3d - dp of size [n][2][3]
    vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>> 
                                            (2,vector<int>(3,-1)));
    
    return getAns(prices,n,0,0,2,dp);
   
}

int main() {

  vector<int> prices = {3,3,5,0,0,3,1,4};
  int n = prices.size();
                                 
  cout<<"The maximum profit that can be generated is "<<maxProfit(prices, n);
}
Output:

The maximum profit that can be generated is 6

Time Complexity: O(N*2*3) 

Reason: There are N*2*3 states therefore at max ‘N*2*3’ new problems will be solved.

Space Complexity: O(N*2*3) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 3D array ( O(N*2*3)).*/


/*#include <bits/stdc++.h>

using namespace std;


int maxProfit(vector<int>& Arr, int n)
{
    // Creating a 3d - dp of size [n+1][2][3] initialized to 0
    vector<vector<vector<int>>> dp(n+1,
                                    vector<vector<int>> 
                                            (2,vector<int>(3,0)));
                                            
    // As dp array is intialized to 0, we have already covered the base case
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
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
    
    
    return dp[0][0][2];
   
}

int main() {

  vector<int> prices = {3,3,5,0,0,3,1,4};
  int n = prices.size();
                                 
  cout<<"The maximum profit that can be generated is "<<maxProfit(prices, n);
}
Output:

The maximum profit that can be generated is 6

Time Complexity: O(N*2*3) 

Reason: There are three nested loops that account for O(N*2*3) complexity.

Space Complexity: O(N*2*3)

Reason: We are using an external array of size ‘N*2*3’. Stack Space is eliminated.*/


/*#include <bits/stdc++.h>

using namespace std;


int maxProfit(vector<int>& Arr, int n)
{
    
    vector<vector<int>> ahead(2,vector<int> (3,0));
    
    vector<vector<int>> cur(2,vector<int> (3,0));
    
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
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
    
    return ahead[0][2];
   
}

int main() {

  vector<int> prices = {3,3,5,0,0,3,1,4};
  int n = prices.size();
                                 
  cout<<"The maximum profit that can be generated is "<<maxProfit(prices, n);
}
Output:

The maximum profit that can be generated is 6

Time Complexity: O(N*2*3)

Reason: There are three nested loops that account for O(N*2*3) complexity

Space Complexity: O(1)*/