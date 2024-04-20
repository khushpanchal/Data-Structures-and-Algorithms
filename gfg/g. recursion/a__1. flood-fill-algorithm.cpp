//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    //Q. https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
    int dirX[4] = {-1, 0, 1, 0};
    int dirY[4] = {0, 1, 0, -1};
    
    bool isValid(int x, int y, int n, int m) {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor, vector<vector<bool> > &vis, int n, int m) {
        
        vis[sr][sc] = true;
        image[sr][sc] = newColor;
        for(int i=0; i<4; i++) {
            int newX = sr+dirX[i];
            int newY = sc+dirY[i];
            if(isValid(newX, newY, n, m) && !vis[newX][newY] && image[newX][newY] == oldColor) {
                dfs(image, newX, newY, oldColor, newColor, vis, n, m);
            }
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        
        int oldColor = image[sr][sc];
        
        dfs(image, sr, sc, oldColor, newColor, vis, n, m);
        return image;
        
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends