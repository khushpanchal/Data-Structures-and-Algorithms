//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
//Q. https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
Node* sortedMerge(Node* a, Node* b)  
{  
    // code here
    Node* head = NULL;
    Node* res = NULL;
    
    if(a->data < b->data){
        head = a;
        res = a;
        a=a->next;
    }
    else{
        head = b;
        res = b;
        b=b->next;
    }
    
    while(a && b){
        if(a->data < b->data){
            res->next = a;
            a=a->next;
            res = res->next;
        }
        else{
            res->next = b;
            b=b->next;
            res = res->next;
        }
    }
    
    while(a){
        res->next = a;
        a=a->next;
        res = res->next;
    }
    while(b){
        res->next = b;
        b=b->next;
        res = res->next;
    }
    
    return head;    
}  