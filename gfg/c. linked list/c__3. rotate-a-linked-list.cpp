//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    //Q. https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1
    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(k==1 && head->next==NULL) return head;
        Node* mid = head;
        while(k!=1) {
            head = head->next;
            k--;
        }
        Node* last = head;
        Node* start = head->next;
        if(start==NULL) return mid;
        while(head->next) {
            head = head->next; 
        }
        last->next = NULL;
        head->next = mid;
        return start;
    
        
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends