//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    //Use topological sort
    void dfs(vector<int> adj[], vector<bool> &vis, stack<int> &s, int node) {
        vis[node] = true;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(adj, vis, s, it);
            }
        }
        
        s.push(node);
    }
    //Q. https://www.geeksforgeeks.org/problems/alien-dictionary/1
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=0; i<N-1; i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.length(), s2.length());
            for(int k=0; k<len; k++) {
                if(s1[k] != s2[k]) {
                    adj[s1[k] - 'a'].push_back(s2[k] - 'a');
                    break;
                }
            }
        }
        
        stack<int> s;
        vector<bool> vis(K, false);
        
        for(int i=0; i<K; i++) {
            if(!vis[i]) {
                dfs(adj, vis, s, i);
            }
        }
        
        string ans;
        
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            
            ans += char(node + 'a');
        }
        
        return ans;
        
    }
       
};


//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends