//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    //Q. https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
    long long inv = 0;

    void merge(long long arr[], long long l, long long m, long long r) {
        
        long long L[m-l+1];
        long long R[r-m];
    
        for(long long i=0; i<m-l+1; i++) L[i] = arr[l+i];
        for(long long i=0; i<r-m; i++) R[i] = arr[m+1+i];
        
        long long i=0;
        long long j=0;
        long long k=l;
        while(i<m-l+1 && j<r-m)
        {
            if(L[i]<=R[j]) arr[k++] = L[i++];
            else
            {
                inv += m-l+1-i;
                arr[k++] = R[j++];
            }
        }
        
        while(i<m-l+1) {
            arr[k++] = L[i++];
        }
        while(j<r-m) {
            arr[k++] = R[j++];
        }
    }
    
    void sortmerge(long long arr[], long long l, long long r)
    {
        if(l<r)
        {
            long long m = l + (r-l)/2;
            sortmerge(arr, l , m);
            sortmerge(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        sortmerge(arr, 0, N-1);
        return inv;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends