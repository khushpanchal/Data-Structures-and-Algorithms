//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//Prims Algorithm
	//Q. https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,0});
        
        int sum = 0;
        vector<bool>vis(V, false);
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            if(vis[node]) continue;
            
            vis[node] = true;
            sum += wt;
            
            for(auto &v:adj[node]){
                int child = v[0], child_wt = v[1];
                pq.push({child_wt, child});
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends