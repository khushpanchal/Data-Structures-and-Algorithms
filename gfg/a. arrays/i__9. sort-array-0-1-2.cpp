//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Q. https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
    void sort012(int a[], int n)
    {
        // code here 
        int low=0; 
        int mid=0;
        int high=n-1;
        
        while(mid<=high) {
            if(a[mid]==0) swap(a[mid++],a[low++]); //send 0 to left most
            else if(a[mid]==1) mid++;
            else if(a[mid]==2) swap(a[mid],a[high--]); //send 2 to right most
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends