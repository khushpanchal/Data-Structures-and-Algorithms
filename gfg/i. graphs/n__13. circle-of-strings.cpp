//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    void dfs(vector<int> adj[], stack<int> &s, vector<bool> &vis, int node) {
        vis[node] = true;
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(adj, s, vis, it);
            }
        }
        
        s.push(node);
    }
    
    void dfs1(vector<int> adjOpp[], int node, vector<bool> &vis1) {
        vis1[node] = true;
        
        for(auto it: adjOpp[node]) {
            if(!vis1[it]) {
                dfs1(adjOpp, it, vis1);
            }
        }
    }
    
    //Q. https://www.geeksforgeeks.org/problems/circle-of-strings4530/1
    int isCircle(int N, vector<string> A)
    {
       vector<int> inOrder(26, 0);
       vector<int> outOrder(26, 0);
       vector<int> adj[26];
       vector<int> adjOpp[26];
       stack<int> s;
       
       for(int i=0; i<A.size(); i++) {
           string s = A[i];
           int len = s.length();
           inOrder[s[0]-'a'] += 1;
           outOrder[s[len-1] - 'a'] += 1;
           
           adj[s[0]-'a'].push_back(s[len-1]-'a');
           adjOpp[s[0]-'a'].push_back(s[len-1]-'a');
           
       }
       
       for(int i=0; i<26; i++) if(inOrder[i] != outOrder[i]) return 0;
       
       vector<bool>vis(26,false);
       
       for(int i=0; i<26; i++) {
           if(outOrder[i] == 0) continue;
           if(!vis[i]) {
               dfs(adj, s, vis, i);
           }
       }
       
       vector<bool> vis1(26, false);
       
       bool flag = true;
       while(!s.empty()) {
           int str = s.top();
           s.pop();
           if(!vis1[str]) {
               if(flag == false) return 0;
               flag = false;
               dfs1(adjOpp, str, vis1);
           }
       }
       return 1;
    }
/*
If there is an eulerian circuit, then chain can be formed, otherwise not. 

Directed graph has eulerian circuit only if in degree and out degree of every vertex is same, and all non-zero degree vertices form a single strongly connected component.

Algo:-
1. Create directed graph with number of vertices equal to the size of alphabet. 
2. For every string add an edge from first character to last character.
If the created graph has eulerian circuit, then return true, else return false.
*/
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends