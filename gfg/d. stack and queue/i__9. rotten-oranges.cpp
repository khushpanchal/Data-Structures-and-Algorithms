//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Triple {
    int first;
    int second;
    int third;
};

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    //Q. https://www.geeksforgeeks.org/problems/rotten-oranges2536/1
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int dirX[4] = {1, -1, 0, 0};
        int dirY[4] = {0, 0, 1, -1};
        
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        
        queue<Triple> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j,0});
                }
            }
        }
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            int curr = q.front().third;
            ans = curr;
            q.pop();
            
            for(int i=0; i<4; i++) {
                int x1 = dirX[i]+x;
                int y1 = dirY[i]+y;
                
                if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1]==1) {
                    grid[x1][y1] = 2;
                    q.push({x1,y1,curr+1});
                }
            }
        }
        
       for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
