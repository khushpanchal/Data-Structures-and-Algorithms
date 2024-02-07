//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //Q. https://www.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int,int> mp;
        for(int i=0; i<2*N-1; i+=2) {
            mp[arr[i]] = arr[i+1];
        }
        int target = 30;
        int start = 1;
        vector<bool> vis(31, false);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        
        int ans=0;
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front();
                q.pop();
                
                for(int i=1; i<=6; i++) {
                    int nxtNode = node+i;
                    if(mp.find(nxtNode) != mp.end()) {
                        nxtNode = mp[nxtNode];
                    }
                    if(nxtNode<=30 && !vis[nxtNode]) {
                        q.push(nxtNode);
                        vis[nxtNode] = true;
                        if(nxtNode == 30) {
                            return ans+1;
                        }
                    }
                }
            }
            ans++;
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends