//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    //Q. https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
    string reverseWords(string S) 
    { 
        int len = S.length();
        string sub;
        vector<string> vec;
        for(int i=0; i<len; i++) {
            if(S[i]=='.') {
                vec.push_back(sub);
                sub="";
            } else {
                sub+=S[i];
            }
        }
        
        vec.push_back(sub); 
        string ans;
        for(int i=vec.size()-1; i>=0; i--) {
            ans+=vec[i];
            if(i!=0)ans+='.';
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends