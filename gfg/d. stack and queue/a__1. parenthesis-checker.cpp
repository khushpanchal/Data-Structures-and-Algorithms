//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Q. https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> stk;
        for(int i=0; i<x.length(); i++) {
            if(x[i] == '(' || x[i] == '{' || x[i] == '[') {
                stk.push(x[i]);
            } else if(x[i] == ')') {
                if(stk.empty() || stk.top()!='(') return false;
                stk.pop();
            } else if(x[i] == '}') {
                if(stk.empty() || stk.top()!='{') return false;
                stk.pop();
            } else if(x[i] == ']') {
                if(stk.empty() || stk.top()!='[') return false;
                stk.pop();
            }
        }
        
        if(stk.empty()) return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends