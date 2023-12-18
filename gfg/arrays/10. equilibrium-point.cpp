//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    //Q. https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
    int equilibriumPoint(long long a[], int n) {
        int pos = -1;
        long long total = 0;
        long long curr = 0;
        
        for(int i=0; i<n; i++) total += a[i];
        
        for(int i=0; i<n; i++) {
            curr += a[i];
            if((curr-a[i])*2 == total-a[i]) {
                pos = i+1;
                break;
            }
        }
        
        return pos;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends