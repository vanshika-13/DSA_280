/*You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the NestedIterator class:

NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
int next() Returns the next integer in the nested list.
boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.
Your code will be tested with the following pseudocode:

initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
If res matches the expected flattened list, then your code will be judged as correct.



Example 1:

Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].*/

#include <bits/stdc++.h>
using namespace std;
class NestedInteger
{
public: // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    vector<int> output;
    int i = 0;
    void helper(vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
            {
                output.push_back(nestedList[i].getInteger());
            }
            else
            {
                helper(nestedList[i].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        helper(nestedList);
    }

    // O(1), O(1)
    int next()
    {
        int ans = -1;
        ans = output.at(i);
        i++;
        return ans;
    }

    // O(N), O(1)
    bool hasNext()
    {
        if (i < output.size())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main()
{
    return 0;
}