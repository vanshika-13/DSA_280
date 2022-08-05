/*Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0*/

#include <bits/stdc++.h>
using namespace std;
int maximalSquare(vector<vector<char>> &mat)
{

    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '1')
                matrix[i][j] = 1;
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = matrix[i][0];
    }
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = matrix[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maxi = max(maxi, dp[i][j]);
        }
    }
    int area = maxi * maxi;
    return area;
}
int main()
{
    return 0;
}

/*
METHOD_2
this method is just same as largest area in histogram, we take out next smaller and previous smaller elemnt for every m[i][j] , while itertating over row , and height will be added from the previous rows value , but if m[i][j]==0 , then height will be 0

class Solution {
public:
     vector<int> nextSmallerElement(vector<int> &arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement( vector<int> &arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }    
    
  
  
  int largestSquareArea(vector<int> &heights, int n) {
        //int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int p;
           p= min(l,b);
            int newArea = p*p;
            area = max(area, newArea);
        }
        return area;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
      int m=matrix[0].size(); 
      int n=matrix.size();
      vector<vector<int>> M(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')  M[i][j]=0;
                
                else M[i][j]=1;
                    
            }
        }
        
        int area = largestSquareArea(M[0], m);
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                
                //row udpate: by adding previous row's value
                if(M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i-1][j];
                
                // if   M[i][j] ==0 then height will be 0;
              
            }
            
            //entire row is updated now
            area = max(area, largestSquareArea(M[i],m));
            
        }
        return area;
    }*/