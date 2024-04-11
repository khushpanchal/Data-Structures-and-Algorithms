//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    //Q. https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long>stk;
        vector<long long> output(n, -1);
        for(int i=n-1; i>=0; i--) {
            while(!stk.empty() && arr[i]>=stk.top()) {
                stk.pop();
            }
            if(!stk.empty()) {
                output[i] = stk.top();
            }
            stk.push(arr[i]);
        }
        
        return output;
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
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends