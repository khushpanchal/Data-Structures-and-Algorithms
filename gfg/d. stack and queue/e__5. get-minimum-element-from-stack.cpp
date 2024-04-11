//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*
Push(x) : Inserts x at the top of stack.

If stack is empty, insert x into the stack and make minEle equal to x.
If stack is not empty, compare x with minEle. Two cases arise:
If x is greater than or equal to minEle, simply insert x.
If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x.
Pop() : Removes an element from top of stack.

Remove element from top. Let the removed element be y. Two cases arise:
If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
If y is less than minEle, the minimum element now becomes (2*minEle – y), update (minEle = 2*minEle – y). Now retrieve previous minimum from current minimum and its value in stack.
*/

//Q. https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
            if(s.empty()) return -1;
            return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           if(s.empty()) return -1;
           if(s.top() >= minEle)
           {
               int temp = s.top();
               s.pop();
               return temp;
           }
           else 
           {
               int flag = minEle;
               minEle = 2*minEle - s.top();
               s.pop();
               return flag;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty()) 
           {
               minEle = x;
               s.push(x);
           }
           else
           {
               if(x >= minEle) s.push(x);
               else
               {
                   s.push(2*x - minEle);
                   minEle = x;
               }
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends