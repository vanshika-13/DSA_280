/*The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.*/

#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    map<int, int> m1;
    stack<int> st;
    int n = nums2.size();

    for (int i = n - 1; i >= 0; i--)
    {
        // this while loop is used for :- if stack is not empty and top value is less than nums2 then we pop that valu bcoz that cant be answer as we want top value should be greater than current value
        while (!st.empty() && st.top() < nums2[i])
        {
            st.pop();
        }

        if (st.empty())
        { // if stack is empty means there is not any value greater than nums2, so simply we put -1 in answer part
            m1[nums2[i]] = -1;
        }

        else
        { // means stack is not empty ans top value of stack is greater than the given nums2 value , so we put this value in map
            m1[nums2[i]] = st.top();
        }

        st.push(nums2[i]);
    }
    vector<int> ans;

    for (auto i : nums1)
    { //  now we traverse nums1 array loop and will put corrosponding value from map in ans
        ans.push_back(m1[i]);
    }

    return ans;
}
int main()
{
    return 0;
}