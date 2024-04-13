//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
//Q. https://www.geeksforgeeks.org/problems/largest-number-possible5028/1
    string findLargest(int N, int S){ //N=5, S=15
        // code here
        if(N*9<S || S<1){
            if(N==1 && S==0) return "0";
            return "-1";
        }

        string ans="";
        
        for(int i=0; i<N; i++){
            if(S>=9){
                ans+="9";
                S-=9;
            }else{
                ans+=to_string(S);
                S=0;
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends