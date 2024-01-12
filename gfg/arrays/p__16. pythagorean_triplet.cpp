//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	// Q. https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1
	bool checkTriplet(int arr[], int n) {
	    // code here
	    int maximum = 0;
	    for(int i=0; i<n; i++) {
	        maximum = max(maximum, arr[i]);
	    }
	    
	    unordered_map<int, int> mp;
	    for(int i=1; i<=maximum; i++) mp[i]=0;
	    for(int i=0; i<n; i++) mp[arr[i]]++;
	    
	    for (int a=1; a<=maximum; a++) {
	        if(mp[a] == 0) continue;
	        
	        for (int b=1; b<=maximum; b++) {
	            if(mp[b] == 0) continue;
	            
	            if ((a == b && mp[a] == 1)) continue;

	            int c = sqrt(a * a + b * b);

	            if ((c * c) != (a * a + b * b)) continue;

	            if (c > maximum) continue;

	            if (mp[c]) {
	                return true;
	            }
	        }
	    }
	    
	    return false;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends