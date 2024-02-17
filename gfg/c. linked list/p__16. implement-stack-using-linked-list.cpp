//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        MyStack *sq = new MyStack();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends


//Function to push an integer into the stack.
//Q. https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1
StackNode* a=NULL;
StackNode* b=NULL;
void MyStack ::push(int x) 
{
    StackNode* temp = new StackNode(x);
    if(top==NULL)
    {
        top = temp;
        a = temp;
        b = temp;
        return;
    }
    top->next = temp;
    top = temp;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if(top == NULL) return -1;
    int ans = top->data;  
    
    if(a->next==NULL)
    {
        top=NULL;
        return ans;
    }
    
    while(a->next->next)
    {
        a = a->next;
    }
    
    a->next = NULL;
    top = a;
    a = b;
    
    return ans;
}
