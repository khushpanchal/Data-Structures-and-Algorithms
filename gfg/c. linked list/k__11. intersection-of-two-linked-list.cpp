//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    //Function to find the intersection of two linked lists.
    //Q. https://www.geeksforgeeks.org/problems/intersection-of-two-linked-list/1
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_set <int> st;
        
        while(head2)
        {
            st.insert(head2->data);
            head2 = head2->next;
        }
        
        Node *newHead=NULL, *newTail=NULL;
        
        while(head1)
        {
            if( st.find(head1->data) != st.end() )
            {
                if(newHead==NULL)
                    newHead = newTail = new Node(head1->data);
                else
                {
                    newTail->next = new Node(head1->data);
                    newTail = newTail->next;
                }
            }
            head1 = head1->next;
        }
        
        return newHead;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends