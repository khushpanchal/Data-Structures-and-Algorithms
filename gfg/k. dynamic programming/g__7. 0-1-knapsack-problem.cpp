//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    //Q. https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int> > dp(n+1, vector<int>(W+1, 0));
       for(int i=1; i<=n; i++) {
           for(int j=1; j<=W; j++) {
               if(wt[i-1]<=j) {
                   //choice to include/exclude the weight
                   dp[i][j] = max(
                       val[i-1] + dp[i-1][j - wt[i-1]], //include
                       dp[i-1][j] //exclude
                    );
               } else {
                   //have to exclude the weight
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends