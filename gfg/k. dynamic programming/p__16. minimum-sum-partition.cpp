//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  //Q. https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0; i<n; i++) sum += arr[i];
	    
	    int halfSum = sum/2;
	    
	    vector<vector<int> > dp(n+1, vector<int>(halfSum+1, 0));
	    
	    for(int i=0; i<=n; i++) {
	        for(int j=0; j<=halfSum; j++) {
	            if(j==0) dp[i][j] = 1;
	            else if(i==0) dp[i][j] = 0;
	            else {
	                if(j>=arr[i-1]) {
	                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	                } else {
	                    dp[i][j] = dp[i-1][j];
	                }
	            }
	        }
	    }
	    
	    for(int i=halfSum; i>=0; i--) {
	        if(dp[n][i] == 1) {
	            return abs(i-(sum-i));
	        }
	    }
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends