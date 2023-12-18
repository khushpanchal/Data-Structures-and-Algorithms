#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Q. https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int> ans;
        int start=0;
        int end=0;
        long long sum=arr[0];
        
        while(end<n) {
            if(sum==s) {
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans;
            } else if(sum<s) {
                end++;
                sum+=arr[end];
            } else {
                sum-=arr[start];
                start++;
                if(start>end) {
                    end++;
                    sum=arr[start];
                }
            }
        }
        if(ans.size()==0) ans.push_back(-1);
        return ans;
    }
};


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}