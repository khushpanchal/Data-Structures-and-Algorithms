//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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

class Solution{
  public:
  //Q. https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
    Node* reverse_list(Node* head)
    {
        Node* prev = NULL;     
        Node* curr = head;   
        Node* next; 
        
        while(curr)
        {
            next = curr->next; 
            curr->next = prev;    
            prev = curr;         
            curr = next; 
        }
        return prev;
        
    }
    
    bool is_identical(Node* n1, Node* n2)
    {

        while(n1!=NULL && n2!=NULL) {
            if(n1->data != n2->data)
                return false;
            n1 = n1->next;
            n2 = n2->next;
        }
        return true;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        int size = 0;
        Node* ptr = head;
        while(ptr!=NULL) {
            size++;
            ptr=ptr->next;
        }
        
        if(size<2) return true;
        
        ptr = head;
        int mid = (size-1)/2;
        while(mid--) {
            ptr = ptr->next;
        }
        Node* head2= ptr->next;
        ptr->next = NULL;
        
        head2 = reverse_list(head2);
        
        bool ans = is_identical(head, head2);
        
        //re arranging to original list
        head2 = reverse_list(head2);
        ptr->next = head2;
        
        return ans;
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends