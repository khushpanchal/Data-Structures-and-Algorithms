//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
//Q. https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++) sum += arr[i];
        
        if(sum%2) return 0;
        
        sum /= 2;
        
        vector<bool> dp(sum+1, false);
        dp[0] = true; //sum 0 can be find by choosing nothing
        
        for(int i=0; i<N; i++) {
            for(int j=sum; j>=1; j--) {
                if(arr[i]<=j) {
                    dp[j] = dp[j] || dp[j-arr[i]];
                }
            }
        }
        return dp[sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends