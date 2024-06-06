//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Q. https://www.geeksforgeeks.org/problems/uncommon-characters4932/1
        string UncommonChars(string A, string B)
        {
            // code here
            vector<int> arr1(26 , 0);
            vector<int> arr2(26 , 0);
            for(char ch: A){
                arr1[ch-'a'] = 1;
            }
            
            for(char ch : B){
                arr2[ch-'a'] =1;
            }
            
            string ans="";
            for(int i = 0 ; i < 26 ; i++){
                if(arr1[i] == 1 && arr2[i]==1 || arr1[i]==0 && arr2[i]==0) continue;
                ans+= 'a'+i;
            }
            if(ans.length()==0) return "-1";
            return ans;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends