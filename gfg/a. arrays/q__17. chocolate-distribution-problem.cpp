//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Q. https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        long long ans = LONG_MAX;
        for(long long i=0; i<n; i++) {
            if(i+m-1 >= n) continue;
            long long minVal = a[i];
            long long maxVal = a[i+m-1];
            long long curr = maxVal - minVal;
            if(curr<=ans) ans = curr;
        }
        
        return ans;
    
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends