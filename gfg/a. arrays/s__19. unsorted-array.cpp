//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


//Q. https://www.geeksforgeeks.org/problems/unsorted-array4925/1
int findElement(int arr[], int n) {
    vector<int> maxi(n,0);
    vector<int> mini(n,0);
    
    maxi[0] = arr[0];
    for(int i=1; i<n; i++) {
        maxi[i] = max(maxi[i-1],arr[i]);
    }
    
    mini[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--) {
        mini[i] = min(mini[i+1],arr[i]);
    }
    
    int ans = -1;
    for(int i=1; i<n-1; i++) {
        if(arr[i] == mini[i] && mini[i] == maxi[i]) {
            return arr[i];
        }
    }
    
    return ans;
}