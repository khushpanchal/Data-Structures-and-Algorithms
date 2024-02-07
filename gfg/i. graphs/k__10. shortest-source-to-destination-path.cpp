//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int dirX[4] = {1, -1, 0, 0};
    int dirY[4] = {0, 0, 1, -1};
    
    int validDirection(int x, int y, int n, int m) {
        return (x>=0 && x<n && y>=0 && y<m);    
    }
    //Q. https://www.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<bool> > vis(N, vector<bool>(M, false));
        queue<pair<int,int>> q;
        if(A[0][0] == 0 || A[X][Y] == 0) return -1;
        q.push({0,0});
        vis[0][0] = true;
        
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            
            if(i==X && j==Y) return A[X][Y] - 1;
            
            for(int k=0; k<4; k++) {
                int x=i+dirX[k];
                int y=j+dirY[k];
                
                if(validDirection(x,y,N,M) && !vis[x][y] && A[x][y] != 0) {
                    if(A[x][y] == 1) A[x][y] = 1 + A[i][j];
                    else A[x][y] = min(A[x][y], A[i][j] + 1);
                    q.push({x,y});
                    vis[x][y] = true;
                } 
                
            }
            
        }

        return - 1;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends