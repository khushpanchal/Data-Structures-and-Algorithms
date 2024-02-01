//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	//Q. https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int ans = 0;
	    vector<int> dp(n);
	    
	    for(int i=0; i<n; i++) {
	        dp[i] = arr[i];
	        ans = max(ans, dp[i]);
	    }
	    
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<i; j++) {
	            if(arr[j]<arr[i] && arr[i]+dp[j] > dp[i]) {
	                dp[i] = arr[i]+dp[j];
	                ans = max(ans, dp[i]);
	            }
	        }
	    }
	    
	    return ans;
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends