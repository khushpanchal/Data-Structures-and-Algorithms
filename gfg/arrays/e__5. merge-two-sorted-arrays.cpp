//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        //https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int e1=n-1; //end index of array 1
            int s2=0; //start index of array 2

            while(s2<m && e1>=0) {
                if(arr1[e1] > arr2[s2]) {
                    swap(arr1[e1], arr2[s2]);
                    e1--;
                    s2++;
                } else {
                    break;
                }
            }
            
            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends