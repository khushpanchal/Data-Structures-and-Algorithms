//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    int dirX[8] = {1, 1, 1, -1, -1, -1, 0, 0};
    int dirY[8] = {1, 0, -1, 1, 0, -1, 1, -1};
    
    bool checkValid(int x, int y, int n, int m) {
        if(x<0 || x>=n || y<0 || y>=m) return false;
        return true;
    }
    
    void dfs(vector<vector<char> >& grid, int i, int j, int n, int m) {
        
        grid[i][j] = 0;
        
        for(int k=0; k<8; k++) {
            if(checkValid(i+dirX[k], j+dirY[k], n, m)) {
                if(grid[i+dirX[k]][j+dirY[k]] == '1') {
                   dfs(grid, i+dirX[k], j+dirY[k], n, m);
                }
            }
        }
        
    }
    //Q. https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends