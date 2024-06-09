//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
//Q. https://www.geeksforgeeks.org/problems/check-frequencies4211/1
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char, int> mp;
	    int mini = INT_MAX;
	    int maxi = INT_MIN;
	    for(int i=0; i<s.length(); i++) {
	        mp[s[i]]++;
	    }
	    
	    for(auto m: mp) {
	        mini = min(m.second, mini);
	        maxi = max(m.second, maxi);
	    }
	    
	    int maxcount = 0;
	    for(auto x: mp){
            if(x.second==maxi) maxcount++;
        }
	    
	    if(mini == maxi) return true;
	    if(maxi-mini == 1 and maxcount==1) return true;
	    if(mini==1 and mp.size()-1 == maxcount) return true; //xxyyz , remove z
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends