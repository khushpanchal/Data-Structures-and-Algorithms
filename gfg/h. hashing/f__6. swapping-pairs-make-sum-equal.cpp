//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
  //Q. https://www.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1
    int findSwapValues(int A[], int n, int B[], int m) {
        // Your code goes here
        sort(A,A+n);
        sort(B,B+m);
        
        int sumA = 0, sumB = 0;
        for(int i=0; i<n; i++) sumA += A[i]; 
        for(int i=0; i<m; i++) sumB += B[i];
	    
	    int a=0, b=0;
	    while(a<n && b<m)
	    {
	        if(2*B[b] - 2*A[a] == sumB-sumA) return 1;
	        else if(2*B[b] - 2*A[a] > sumB-sumA) a++;
	        else b++;
	    }
	    
	    return -1;
	
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends