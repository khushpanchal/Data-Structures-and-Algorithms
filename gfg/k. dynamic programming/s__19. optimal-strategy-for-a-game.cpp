//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    long long min(long long a, long long b) {
        if(a<b) return a;
        return b;
    } 
    
    long long max(long long a, long long b) {
        if(a>b) return a;
        return b;
    }
    
    long long game(int i, int j, int arr[] ,vector<vector<int>> &dp)
    {
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long l=arr[i]+min(game(i+2,j,arr,dp),game(i+1,j-1,arr,dp));
        long long r=arr[j]+min(game(i,j-2,arr,dp),game(i+1,j-1,arr,dp)) ;
        
        return dp[i][j]=max(l,r);
    }
    
    //Q. https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
    long long maximumAmount(int arr[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return game(0,n-1,arr,dp);
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
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        Solution ob;
        cout<< ob.maximumAmount(a,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends