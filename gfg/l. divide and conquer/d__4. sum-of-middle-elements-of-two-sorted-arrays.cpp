//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
//Q. https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1
    int getMidSum(int *arr, int n) {
        if (n%2 == 0)
            return (arr[n/2] + arr[n/2 - 1]);
        else
            return 2*arr[n/2];
    }

    //Function to find the middle sum of two arrays.
    int findMidSum(int ar1[], int ar2[], int n) {

        if (n<=0) return -1;
        if (n==1) return (ar1[0] + ar2[0]);
        if (n==2) return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]));

        int m1 = getMidSum(ar1, n);
        int m2 = getMidSum(ar2, n);
        
        if (m1 == m2) return m1;
        
        if (m1 < m2) {
            if(n%2 == 0) return findMidSum(ar1 + n/2 - 1, ar2, n - n/2 + 1);
            return findMidSum(ar1 + n/2, ar2, n - n/2);
        }

        if (n%2 == 0) return findMidSum(ar2 + n/2 - 1, ar1, n - n/2 + 1);
        return findMidSum(ar2 + n/2, ar1, n - n/2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends