//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Node {
    public:
        int key;
        int value;
        Node *next; 
        Node *pre;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            next = NULL;
            pre = NULL;
        }
};

//Q. https://www.geeksforgeeks.org/problems/lru-cache/1
class LRUCache
{
    public:
        unordered_map<int, Node*> mp;
        int capacity = 0; //excluding head and tail
        int count = 0;
        Node *head;
        Node *tail;
    
        LRUCache(int cap)
        {
            capacity = cap;
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            head->pre = NULL;
            tail->next = NULL;
            tail->pre = head;
            count = 0;
        }
    
        void addToHead(Node *node)
        {
            node->next = head->next;
            node->next->pre = node;
            node->pre = head;
            head->next = node;
        }
    
        void deleteNode(Node *node)
        {
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }
        
        int GET(int key)
        {
            if (mp.find(key) != mp.end())
            {
                Node *node = mp[key];
                int result = node->value;
                
                deleteNode(node);
                addToHead(node);
                
                return result;
            }
            return -1;
        }
    
        void SET(int key, int value)
        {
            if (mp.find(key) == mp.end()) {
                Node *node = new Node(key, value);
                mp[key] = node;
                if (count < capacity) {
                    count++;
                    addToHead(node);
                } else {
                    mp.erase(tail->pre->key);
                    deleteNode(tail->pre);
                    addToHead(node);
                }
            } else {
                Node *node = mp[key];
                node->value = value;
                deleteNode(node);
                addToHead(node);
            }
        }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
