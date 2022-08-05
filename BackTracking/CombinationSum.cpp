/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> v;
void solve(vector<int> &candidates, int target, int i)
{
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    else if (target < 0 || i >= candidates.size())
    {
        return;
    }
    if (candidates[i] <= target)
    {
        v.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1);
        v.pop_back();
    }
    while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
    {
        i++;
    }
    solve(candidates, target, i + 1);
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    solve(candidates, target, 0);
    return ans;
}
int main()
{
    return 0;
}


/*
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSubsetSum(int arr[], int n, int sum,
                 vector<vector<int> >& dp)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
 
    // return solved subproblem
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }
 
    // If last element is greater than sum, then
    // ignore it
    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum, dp);
 
    /* else, check if sum can be obtained by any of
        the following
        (a) including the last element
        (b) excluding the last element
    
    // also store the subproblem in dp matrix
    return dp[n][sum]
           = isSubsetSum(arr, n - 1, sum, dp)
             || isSubsetSum(arr, n - 1, sum - arr[n - 1],
                            dp);
}
 
// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
int equalPartition(int n,int arr[])
{
    // Calculate sum of the elements in array
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    // If sum is odd, there cannot be two subsets
    // with equal sum
    if (sum % 2 != 0)
        return false;
 
    // To store overlapping subproblems
    vector<vector<int> > dp(n + 1,
                            vector<int>(sum + 1, -1));
 
    // Find if there is subset with sum equal to
    // half of total sum
    return isSubsetSum(arr, n, sum / 2, dp);
}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
*/

/*// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int equalPartition(int n,int arr[])
{
    // Calculate sum of the elements in array
    int sum = 0;
    int i, j;
 
    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    bool part[sum / 2 + 1];
 
    // Initialize the part array
    // as 0
    for (i = 0; i <= sum / 2; i++) {
        part[i] = 0;
    }
 
    // Fill the partition table in bottom up manner
 
    for (i = 0; i < n; i++) {
        // the element to be included
        // in the sum cannot be
        // greater than the sum
        for (j = sum / 2; j >= arr[i];
             j--) { // check if sum - arr[i]
            // could be formed
            // from a subset
            // using elements
            // before index i
            if (part[j - arr[i]] == 1 || j == arr[i])
                part[j] = 1;
        }
    }
 
    return part[sum / 2];
}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
*/