//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Q. https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
    int search(int arr[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
	    while(l<=h){
	        int m = l + (h-l)/2;
	        
	        if(arr[m]==key){
	            return m;
	        }
	        else if(arr[l]<=arr[m]){
	            if(key>=arr[l] && key<=arr[m]) h=m-1;
	            else l=m+1;
	        }
	        else if(arr[h]>arr[m]){
	            if(key<=arr[h]&& key>=arr[m]) l=m+1;
	            else h=m-1;
	        }
	        
	    }
	    return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends