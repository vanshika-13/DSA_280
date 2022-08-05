/*You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.*/

#include<bits/stdc++.h>
using namespace std;
int deleteAndEarn(vector<int>& nums) {
        int freq[10001];
        int n = nums.size();
        memset(freq,0,sizeof(freq));
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int dp[10001];
        memset(dp,0,sizeof(dp));
        dp[1] = 1*freq[1];
        dp[0] = 0;
        for(int i=2;i<10001;i++){
            dp[i] = max(dp[i-2] + i*freq[i],dp[i-1]);
        }
        int ans = -1;
        for(int i=0;i<10001;i++){
            ans = max(ans,dp[i]);
        }
        return ans;  
    }
int main()
{
    return 0;
}