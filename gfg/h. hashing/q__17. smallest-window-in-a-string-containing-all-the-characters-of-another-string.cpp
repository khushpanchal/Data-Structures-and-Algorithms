//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    //Q. https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
    string smallestWindow (string s, string p)
    {
        // Your code here
        int m[256]={0};
        int cnt=0;
        for(int i=0;i<p.length();i++) {
           if(m[p[i]]==0)
           cnt++;
           m[p[i]]++;
        }
        
        int i=0;
        int j=0;
        int start=0;
        int ans=INT_MAX;
        
        while(j < s.length()) {
            m[s[j]]--;
            if(m[s[j]]==0) cnt--;
            if(cnt==0) {
                while(cnt < 1) {
                    if(ans > j-i+1) {
                        ans=min(ans,j-i+1);
                        start=i;
                    }
               
                    m[s[i]]++;
                    if(m[s[i]]==1) cnt++;
                    i++;
                }
           
            }
            j++;
        }
        
        if (ans != INT_MAX)
            return s.substr(start, ans);
        else
            return "-1";
    
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends