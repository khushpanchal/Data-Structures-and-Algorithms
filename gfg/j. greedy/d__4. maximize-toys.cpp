//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    //Q. https://www.geeksforgeeks.org/problems/maximize-toys0331/1
    int toyCount(int N, int K, vector<int> arr)
    {
        // code here
        sort(arr.begin(), arr.end());
        int count=0;
        int curr=0;
        for(int i=0; i<N; i++) {
            curr += arr[i];
            if(curr<=K) {
                count++;
            } else break;
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.toyCount(N, K, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends