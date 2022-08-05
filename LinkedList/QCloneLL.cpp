/*You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

ArbitLinked List1

Example 1:

Input:
N = 4, M = 2
value = {1,2,3,4}
pairs = {{1,2},{2,4}}
Output: 1
Explanation: In this test case, there
are 4 nodes in linked list.  Among these
4 nodes,  2 nodes have arbitrary pointer
set, rest two nodes have arbitrary pointer
as NULL. Second line tells us the value
of four nodes. The third line gives the
information about arbitrary pointers.
The first node arbitrary pointer is set to
node 2.  The second node arbitrary pointer
is set to node 4.
Example 2:

Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
Explanation: In the given testcase ,
applying the method as stated in the
above example, the output will be 1.*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int v)
    {
        val = v;
    }
};
Node *copyRandomList(Node *head)
{
    Node *iter = head;
    Node *front = head;

    // First round: make copy of each node,
    // and link them together side-by-side in a single list.
    while (iter != NULL)
    {
        front = iter->next;

        Node *copy = new Node(iter->val);
        iter->next = copy;
        copy->next = front;

        iter = front;
    }

    // Second round: assign random pointers for the copy nodes.
    iter = head;
    while (iter != NULL)
    {
        if (iter->random != NULL)
        {
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }

    // Third round: restore the original list, and extract the copy list.
    iter = head;
    Node *pseudoHead = new Node(0);
    Node *copy = pseudoHead;

    while (iter != NULL)
    {
        front = iter->next->next;

        // extract the copy
        copy->next = iter->next;

        // restore the original list
        iter->next = front;

        copy = copy->next;
        iter = front;
    }

    return pseudoHead->next;
}
int main()
{
    return 0;
}