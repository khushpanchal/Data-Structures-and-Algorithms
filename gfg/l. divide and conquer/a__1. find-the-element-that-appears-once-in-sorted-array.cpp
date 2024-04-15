//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
  //Q. https://www.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1
    int findOnce(int arr[], int n)
    {
        //code here.
        
        int l = 0, h = n-1;
        if(l==h) return arr[l];
        if(arr[0] < arr[1]) return arr[0];
        if(arr[n-1] > arr[n-2]) return arr[n-1];
        
        while(l <= h){
            int mid = (l+h)/2;
                
            if(arr[mid] < arr[mid+1] && arr[mid]>arr[mid-1]){
                return arr[mid];
            } 
            if(arr[mid] == arr[mid-1]){
                if(mid%2!=0)
                    l = mid+1;
                else
                    h = mid-1;
            }else if(arr[mid] == arr[mid+1]){
                if(mid%2!=0)
                    h = mid-1;
                else
                    l = mid+1;
                    
            }
        }
        return -1;
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
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends