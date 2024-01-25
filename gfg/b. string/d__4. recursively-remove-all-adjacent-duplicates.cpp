//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Q. https://www.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1
    string rremove(string s){
        // code here
        string str;
        int temp = 0;
        int i=0;
        for(i=0; i+1<s.length(); i++)
        {
            temp = 0;
            while(i+1<s.length() && s[i] == s[i+1])
            {
                temp = 1;
                i++;
            }
            if(temp==0 && i<s.length())str.push_back(s[i]);
        }
        if(i<s.length()) str.push_back(s[i]);
        
        if(s==str) return str;
        
        return rremove(str);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends