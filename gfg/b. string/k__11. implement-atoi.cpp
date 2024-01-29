//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  //Q. https://www.geeksforgeeks.org/problems/implement-atoi/1
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int n=str.length();
        int neg = 0;
        int ans = 0;
        if(str[0]=='-') neg = 1;
        else if(str[0]<'0' || str[0]>'9') return -1;
        else ans = ans*10 + (str[0] - '0');
        
        for(int i=1; i<n; i++)
        {
            if(str[i]<'0' || str[i]>'9') return -1;
            ans = ans*10 + (str[i] - '0');
        }
        if(neg==1) ans = ans*-1;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends