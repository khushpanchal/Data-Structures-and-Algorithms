//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  //Q. https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char, int>mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int n = str.length();
        int num = mp[str[n-1]];
        for(int i=n-1; i>=0; i--) {
            if(mp[str[i-1]]<mp[str[i]]) {
                num-=mp[str[i-1]];
            } else {
                num+=mp[str[i-1]];
            }
        }
        return num;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends