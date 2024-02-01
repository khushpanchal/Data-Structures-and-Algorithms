//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
  //Q. https://www.geeksforgeeks.org/problems/find-optimum-operation4504/1
    int minOperation(int n)
    {
        int ops = 0;
        while(n) {
            if(n%2) { //odd
                n--;
            } else { //even
                n/=2;
            }
            ops++;
        }
        return ops;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends