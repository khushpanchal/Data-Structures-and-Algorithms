//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    //Q. https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string ans = arr[0];
        for(int i=1; i<N; i++) {
            int curr = arr[i].length();
            int pre = ans.length();
            int j=0;
            string newPre;
            while(j<curr && j<pre) {
                if(arr[i][j] == ans[j]) {
                    newPre += ans[j];
                    j++;
                }
                else break;
            }
            ans = newPre;
        }
        if(ans == "") return "-1";
        return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends