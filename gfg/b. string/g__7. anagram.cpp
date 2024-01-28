//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    //Q. https://www.geeksforgeeks.org/problems/anagram-1587115620/1
    bool isAnagram(string a, string b){
        
        // Your code here
        vector<int> vec(256, 0);
        for(int i=0; i<a.length(); i++) {
            vec[a[i]]++;
        }
        for(int i=0; i<b.length(); i++) {
            vec[b[i]]--;
        }
        bool ans = true;
        for(int i=0; i<256; i++) {
            if(vec[i] != 0) ans = false;
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends