//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    //Q. https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;
        int currLeader=0;
        for(int i=n-1; i>=0; i--){
            if(a[i]>=currLeader){
                ans.push_back(a[i]);
                currLeader=a[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends