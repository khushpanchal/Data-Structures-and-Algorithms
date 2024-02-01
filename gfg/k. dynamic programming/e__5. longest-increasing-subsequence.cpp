//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    //Q. https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
    int longestSubsequence(int n, int a[])
    {
      vector<int> tail;
      //intiution - https://youtu.be/on2hvxBXJH4?si=5F6O_6fO5TAWCyTI
      tail.push_back(a[0]);
       
      for(int i=1; i<n; i++) {
          if(a[i] < tail[0]) {
              tail[0] = a[i];
          }
           
          else if(a[i] > tail[tail.size()-1]) {
              tail.push_back(a[i]);
          }
           
          else {
              int ind = lower_bound(tail.begin(), tail.end(), a[i]) - tail.begin();
              tail[ind] = a[i];
          }
      }
      return tail.size();
        // DP with Memoization (O(n^2)) approach
        // vector<int> dp(n, 1);
        // int maxi = 1;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < i; j++)
        //     {
        //         if (a[j] < a[i] && 1 + dp[j] > dp[i])
        //         {
        //             dp[i] = 1 + dp[j];
        //         }
        //     }
        //     maxi = max(maxi, dp[i]);
        // }
        // return maxi;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends