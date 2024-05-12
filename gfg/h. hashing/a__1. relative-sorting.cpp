//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function template in C++

unordered_map<int, int> mp;

class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
//Q. https://www.geeksforgeeks.org/problems/relative-sorting4323/1
    static bool comp(int x, int y) {
        //true -> x comes before y
        //false -> y comes before x
        if(mp.find(x) != mp.end() && mp.find(y) != mp.end()) {
            if(mp[x]<mp[y]) return true;
            return false;
        }
        
        if(mp.find(x) != mp.end()) {
            return true;
        }
        
        if(mp.find(y) != mp.end()) {
            return false;
        }
        
        if(x<y) return true;
        return false;
        
    }
    
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        //Your code here
        mp.clear();
        for(int i=0; i<A2.size(); i++) if(mp.find(A2[i]) == mp.end()) mp[A2[i]] = i;
        
        sort(A1.begin(), A1.end(), comp);
        return A1;
    } 
};

//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 

// } Driver Code Ends