//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Q. https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
	    unordered_set<string> st;
	    void recursion(string S, int l, int r) {
	        if(l==r) {
	            st.insert(S);
	        }
	        for(int i=l; i<=r; i++) {
	            swap(S[i],S[l]);
	            recursion(S, l+1, r);
	            swap(S[i],S[l]);
	        }
	        
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
            recursion(S, 0, S.length()-1);
            for(auto s: st) {
                ans.push_back(s);
            }
            sort(ans.begin(), ans.end());
            return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends