//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    //Q. https://www.geeksforgeeks.org/problems/choose-and-swap0531/1
    //logic - store position of first occurance of each character in a string, sort it and compare first unmatcher char and swap them
    string chooseandswap(string a){
        // Code Here
        vector<int> vec(26, INT_MAX);
        unordered_map<int,int> mp;
        for(int i=0; i<a.length(); i++) {
            int pos = a[i]-'a';
            if(vec[pos]==INT_MAX) {
                vec[pos] = i;
                mp[i]=pos;
            }
        }
        
        vector<int> comp = vec;
        sort(comp.begin(), comp.end());
        
        char c1,c2;
        
        int k=0;
        for(int i=0; i<26; i++) {
            if(vec[i]!=INT_MAX) {
                if(vec[i]==comp[k]) {
                    k++;
                } else {
                    c1='a'+i;
                    c2='a'+mp[comp[k]];
                    break;
                }
            }
        }
        
        for(int i=0; i<a.length(); i++) {
            if(a[i]==c1) a[i]=c2;
            else if(a[i]==c2) a[i]=c1;
        }
        
        return a;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends