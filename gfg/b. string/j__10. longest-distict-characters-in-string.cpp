//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

//Q. https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1
int longestSubstrDistinctChars (string S)
{
    // your code here
    int s=0;
    int e=1;
    int n=S.length();
    if(n==1) return 1;
    unordered_set<int> st;
    st.insert(S[0]);
    int curr=0;
    int ans=1;
    while(s<=e && e<n) {
        if(st.find(S[e]) != st.end()) {
            st.erase(S[s]);
            s++;
        } else {
            st.insert(S[e]);
            e++;
        }
        curr = e-s;
        ans = max(ans, curr);
    }
    
    return ans;
    
}