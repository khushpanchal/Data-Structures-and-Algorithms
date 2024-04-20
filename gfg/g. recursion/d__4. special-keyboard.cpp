//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
//Q. https://www.geeksforgeeks.org/problems/special-keyboard3018/1
    long long int optimalKeys(int N){
        // code here
        int n = N;
        int dp[76]={0};
        for(int i=1;i<=6;i++)
        {
            dp[i]=i;
        }
        for(int i=7;i<=n;i++)
        {
            //dp[i]=0;
            for(int a=i-2;a>=1;a--)
            {
                int cur=(i-a)*dp[a-1];
                if(cur>dp[i])
                    dp[i]=cur;
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends