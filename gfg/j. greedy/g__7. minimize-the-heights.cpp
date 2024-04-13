//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  //Q. https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        //Target - reduce the tallest, maximize the shortest
        
        sort(arr, arr+n);
        int diff = arr[n-1]-arr[0];
        int maxi = arr[n-1]-k; //compare with all arr[n-i]+k (i>1)
        int mini = arr[0]+k; //compare with all arr[i]-k (i>0)
        
        int shortest = 0, tallest = 0;
        
        for(int i=1; i<n; i++) {
            if(arr[i]-k<0) continue;
            shortest = min(mini, arr[i]-k);
            tallest = max(maxi, arr[i-1]+k);
            diff = min(diff, tallest-shortest);
        }
        
        return diff;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends