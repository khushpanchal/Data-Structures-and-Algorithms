//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    //Q. https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
    bool dfs(int i, vector<int> adj[], vector<bool> &vis, vector<bool> &temp) {
        temp[i] = true;
        
        for(auto j: adj[i]) {
            if(!temp[j]) {
                if(!vis[j]) {
                    if(dfs(j, adj, vis, temp)) return true;
                }
            }
            else {
                return true;
            }
        }
        
        temp[i] = false;
        vis[i] = true;
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V, false);
        vector<bool> temp(V, false); //always false from fresh dfs cycle (case //0-->1<--2)
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, temp)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends