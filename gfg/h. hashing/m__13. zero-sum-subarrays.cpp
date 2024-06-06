//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    //Q. https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        unordered_map<long long,long long> mp;
        mp[arr[0]]++;
        for(int i=1; i<n; i++) 
        {
            arr[i] += arr[i-1];
            mp[arr[i]]++;
        }
        
        int ans = 0;
        if(mp.find(0) != mp.end()) ans+=mp[0];
        
        for(auto x: mp)
        {
            if(x.second == 1) continue;
            else
            {
                ans += (x.second * (x.second-1))/2;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends