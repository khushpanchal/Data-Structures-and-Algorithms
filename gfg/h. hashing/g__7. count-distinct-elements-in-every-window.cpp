//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
  //Q. https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int> ans;
        unordered_map<int, int> mp;
        int curr = 0;
        int i=0;
        for(i=0; i<k; i++) {
            mp[A[i]]++;
            if(mp[A[i]] == 1) curr++;
        }
        ans.push_back(curr);
        
        while(i<n) {
            int s = i-k;
            mp[A[s]]--;
            if(mp[A[s]]==0) curr--;
            mp[A[i]]++;
            if(mp[A[i]]==1) curr++;
            i++;
            ans.push_back(curr);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends