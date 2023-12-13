#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // Q. https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long max(long long x, long long y) {
        return x>y ? x: y;
    }
    
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long ans = arr[0];
        long long curr = arr[0];
        
        for(int i=1; i<n; i++) {
            curr = max(arr[i], curr+arr[i]);
            ans = max(ans, curr);
        }
        
        return max(ans,curr);
        
    }
};


int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}