//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
  //Q. https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
    int minJumps(int arr[], int n){
        // Your code here
        int jumps = 0;
        int curr = 0; 
        int farthest = 0;
        
        for (int i = 0; i < n - 1; i++) {
             farthest = max(farthest, i + arr[i]);
             if (i == curr) {
                jumps++;
                if(farthest<=i) return -1;//cannot move after this point
                curr = farthest;
            }
        }
        return jumps;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends