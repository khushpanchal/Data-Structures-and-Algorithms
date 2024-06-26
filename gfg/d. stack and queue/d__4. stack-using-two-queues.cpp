//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
//Q. https://www.geeksforgeeks.org/problems/stack-using-two-queues/1
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code
        if(q1.empty()) return -1;
        int lastElement = -1;
        while(!q1.empty()) {
            lastElement = q1.front();
            q1.pop();
            if(!q1.empty()) {
                q2.push(lastElement);
            }
        }
        
        int ans = lastElement;
        
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        
        return ans;
}
