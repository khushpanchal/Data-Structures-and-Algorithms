//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    //Q. https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.size()!=str2.size()) return false;
        if(str1.size()<=2 || str2.size()<=2) return false;
        if(str1.substr(2,str1.length()-2) + str1.substr(0,2) == str2) return true;
        if(str1.substr(str1.length()-2, 2) + str1.substr(0,str1.length()-2) == str2) return true;
        return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends