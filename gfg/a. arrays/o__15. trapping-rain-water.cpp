//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    //Q. https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int a[n];
        a[0] = arr[0];
        int b[n];
        b[n-1] = arr[n-1];
        for(int i=1; i<n; i++) a[i] = max(arr[i],a[i-1]);
        for(int i=n-2; i>=0; i--) b[i] = max(arr[i],b[i+1]);
        long long ans=0;
        for(int i=0; i<n; i++) ans+=min(a[i],b[i])-arr[i];
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends