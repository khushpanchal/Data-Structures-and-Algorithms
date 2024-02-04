//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	
	void dfs(vector<vector<int>>& adj, stack<int> &s, vector<bool> &vis, int node) {
	    vis[node] = true;
	    for(auto it: adj[node]) {
	        if(!vis[it]) {
	            dfs(adj, s, vis, it);
	        }
	    }
	    s.push(node);
	}
	
	void dfs1(vector<vector<int>>& mat, vector<bool> &vis1, int node) {
	    vis1[node] = true;
	    for(auto it: mat[node]) {
	        if(!vis1[it]) {
	            dfs1(mat, vis1, it);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
	//Q. https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<vector<int> > mat(V);
        for(int i=0; i<adj.size(); i++) {
            for(int j=0; j<adj[i].size(); j++) {
                mat[adj[i][j]].push_back(i);
            }
        }
        
        stack<int> s;
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(adj, s, vis, i);
            }
        }
        
        int ans=0;
        vector<bool> vis1(V, false);
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!vis1[node]) {
                dfs1(mat, vis1, node);
                ans++;
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends