/*How to implement LRU caching scheme? What data structures should be used?
We are given the total possible page numbers that can be referred. We are also given a cache (or memory) size (The number of page frames that the cache can hold at a time). The LRU caching scheme is to remove the least recently used frame when the cache is full and a new page is referenced which is not there in the cache. Please see the Galvin book for more details (see the LRU page replacement slide here).


We use two data structures to implement an LRU Cache.

Queue is implemented using a doubly-linked list. The maximum size of the queue will be equal to the total number of frames available (cache size). The most recently used pages will be near the front end and the least recently used pages will be near the rear end.
A Hash with the page number as key and the address of the corresponding queue node as value.
When a page is referenced, the required page may be in the memory. If it is in the memory, we need to detach the node of the list and bring it to the front of the queue.
If the required page is not in memory, we bring that in memory. In simple words, we add a new node to the front of the queue and update the corresponding node address in the hash. If the queue is full, i.e. all the frames are full, we remove a node from the rear of the queue, and add the new node to the front of the queue.

Example – Consider the following reference string :

1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
Find the number of page faults using the least recently used (LRU) page replacement algorithm with 3-page frames. */

// Java program to implement LRU cache
// using LinkedHashSet
// We can use stl container list as a double
// ended queue to store the cache keys, with
// the descending time of reference from front
// to back and a set container to check presence
// of a key. But to fetch the address of the key
// in the list using find(), it takes O(N) time.
// This can be optimized by storing a reference
//	 (iterator) to each key in a hash map.
#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_)
    {
        if (m.find(key_) != m.end())
        {
            node *resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }

        return -1;
    }

    void put(int key_, int value)
    {
        if (m.find(key_) != m.end())
        {
            node *existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key_, value));
        m[key_] = head->next;
    }
};
int main()
{
}
