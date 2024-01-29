//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  //Q. https://www.geeksforgeeks.org/problems/form-a-palindrome1455/1
    int countMin(string str){
    //complete the function here
        //find longest palindrome in string
        string str1 = str;
        reverse(str1.begin(), str1.end());
        int n = str.length();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 || j==0) {
                    if(str[i]==str1[j]) dp[i][j]=1;
                    else if(i>0) dp[i][j] = dp[i-1][j];
                    else if(j>0) dp[i][j] = dp[i][j-1];
                    
                    continue;
                }
                
                if(str[i]==str1[j]) dp[i][j] = 1 +dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        //subtract longest palindrome length from string length
        return n-dp[n-1][n-1];
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends