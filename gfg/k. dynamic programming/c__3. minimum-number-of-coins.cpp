//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        //Q. https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
        vector<int> notes = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1}; 
        vector<int> ans;
        int i=0;
        int currNote = notes[i];
    
        while(N) {
            if(N-currNote >= 0) {
                ans.push_back(currNote);
                N -= currNote;
            } else {
                i++;
                currNote = notes[i];
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends