//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    int dirX[4] = {1, -1, 0, 0};
    int dirY[4] = {0, 0, 1, -1};
    
    bool validDirection(int x, int y, int n, int m) {
        return (x>=0 && y>=0 && x<n && y<m);
    }
    //Q. https://www.geeksforgeeks.org/problems/find-whether-path-exist5238/1
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        int m= grid[0].size();
        
        int sx=0;
        int sy=0;
        
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(grid[i][j] == 1) sx = i, sy=j;
        
        queue<pair<int,int>>q;
        q.push({sx,sy});
        grid[sx][sy] = 0;
        
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            
            for(int k=0; k<4; k++) {
                int x = i+dirX[k];
                int y = j+dirY[k];
                
                if(validDirection(x,y,n,m) && grid[x][y] != 0) {
                    if(grid[x][y] == 2) return true;
                    q.push({x,y});
                    grid[x][y] = 0;
                }
            }
        }
        
        return false;
        
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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends