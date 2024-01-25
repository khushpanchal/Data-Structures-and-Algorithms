//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  //Q. https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
    string longestPalin (string S) {
        
        int high,low,start=0,max=1;
        int len=S.size();
        
        for(int i=1;i<len;i++) {
            //check for even length palindrome
            low=i-1;
            high=i;
            while(low>=0 && high<len && S[low]==S[high]){
                if(high-low+1>max){
                    max=high-low+1;
                    start=low;
                }
                --low;
                ++high;
            }
            
            //check for odd length palindrome with center i
            low=i-1;
            high=i+1;
            while(low>=0 && high<len && S[low]==S[high]){
                if(high-low+1>max){
                    max=high-low+1;
                    start=low;
                }
                --low;
                ++high;
            }
            
        }
        return S.substr(start,max);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends