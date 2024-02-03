//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    
    bool valid(int n, int m, int x, int y) {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    
    void dfs(vector<vector<int> > &matrix, vector<vector<int> > &dp, int i, int j, int n, int m) {
        
        for(int k=0; k<4; k++) {
            int x = i + dirX[k];
            int y = j + dirY[k];
            
            if(valid(n, m, x, y) && matrix[i][j] < matrix[x][y]) {
                if(dp[i][j] + 1 > dp[x][y]) {
                    dp[x][y] = dp[i][j] + 1;
                    dfs(matrix, dp, x, y, n, m);
                }
            }
        }
        
    }
    //Q. https://www.geeksforgeeks.org/problems/longest-path-in-a-matrix3019/1
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int> > dp(n, vector<int> (m, 1));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dp[i][j]==1) {
                    dfs(matrix, dp, i, j, n, m);
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends