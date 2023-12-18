//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    //Q. https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
    int findPlatform(int arr[], int dep[], int n)
    {
    	//Think like real railway station
    	//train arrival utilize 1 platform, train departture frees up 1 platform
    	//train may be different
    	//sort all arrival and departure times.
    	//traverse from lowest to highest time 
    	//if time is arrival (increase platform), if time is departure (decrease platform)
    	sort(arr, arr+n);
     	sort(dep, dep+n);
   	    int i=0; //arrival time index
   	    int j=0; //dep time index
   	    int plat = 0; //max of this is the minimum platform required
   	    int ans = 0;
   	    
   	    while(i<n && j<n) {
   	        if(arr[i] <= dep[j]) {
   	            plat++;
   	            i++;
   	        } else {
   	            plat--;
   	            j++;
   	        }
   	        ans = max(ans, plat);
   	    }
   	    // no need of below
   	    // while(i++<n) plat++;
   	    // while(j++<n) plat--;
   	    
   	    return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends