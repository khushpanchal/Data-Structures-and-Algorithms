//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	//Dijkstra Algo
	int dirX[4] = {0,0,-1,1};
	int dirY[4] = {1,-1,0,0};
	
	bool checkValidDirection(int x, int y, int n, int m) {
	    return (x>=0 && y>=0 && x<n && y<m);
	}
	//Q. https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int> > ans(n, vector<int>(m, 100000000));
       
        priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int,pair<int,int>>>> q;
        q.push({grid[0][0],{0,0}});
        ans[0][0] = grid[0][0];
        
        while(!q.empty()) {
            pair<int,pair<int,int> >p = q.top();
            q.pop();
            int i = p.second.first;
            int j = p.second.second;
            int wt = p.first;
            
            for(int k=0; k<4; k++) {
                int x = i+dirX[k];
                int y = j+dirY[k];
                
                if(checkValidDirection(x,y,n,m) &&grid[x][y] + wt < ans[x][y]) {
                    q.push({grid[x][y] + wt,{x,y}});
                    ans[x][y] = wt + grid[x][y];
                    if(x==n-1 && y==m-1) {
                        return wt + grid[x][y];
                    }
                }
            }
        }
        
        return ans[n-1][m-1];
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends