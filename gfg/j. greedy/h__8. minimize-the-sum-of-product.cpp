//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Q. https://www.geeksforgeeks.org/problems/minimize-the-sum-of-product1525/1
    long long int minValue(int a[], int b[], int n)
    {
        // Your code goes here
        long long sum = 0;
        
        sort(a,a+n);
        sort(b,b+n, greater<long long>());
        
        for(int i=0;i<n;i++)
            sum += a[i]*b[i];
            
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}
// } Driver Code Ends