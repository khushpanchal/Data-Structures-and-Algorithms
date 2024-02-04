//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    //Q. https://www.geeksforgeeks.org/problems/minimum-swaps/1
	int minSwaps(vector<int>&nums)
	{
	    int N = nums.size();
	    bool vis[N] = {false};
        vector<pair<int,int>> vec;
        
        for(int i=0; i<N; i++)
        {
            vec.push_back(make_pair(nums[i], i));
        }
        
        sort(vec.begin(), vec.end());
        
        int ans = 0;
        int cycle = 0;
        
        for(int i=0; i<N; i++)
        {
            cycle = 0;
            int j = i;
            if(vec[j].second == j) continue;
            while(!vis[j])
            {
                vis[j] = true;
                
                j = vec[j].second;
                cycle++;
            }
            if(cycle>0) ans+=cycle-1;
        }
        return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends