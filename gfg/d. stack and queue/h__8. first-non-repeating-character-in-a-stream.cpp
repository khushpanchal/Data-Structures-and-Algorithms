//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Q. https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
class Solution {
	public:
		string FirstNonRepeating(string A){
	    // Code here
    	    queue<char> q; //queue contains non repeating characters (front of queue is first non repeating character)
    	    unordered_map<char, int> mp;
    	    string ans;
    
    	    for(int i=0; i<A.length(); i++) {
    	        mp[A[i]]++;
    	        if(mp[A[i]] == 1) {
    	            q.push(A[i]);
    	        }
    	        
    	        while(!q.empty()) {
    	            char front = q.front();
    	            if(mp[front] > 1) {
    	                q.pop();
    	            } else {
    	                break;
    	            }
    	        }
    	        
    	        if(q.empty()) {
    	            ans += '#';
    	        } else {
    	            ans += q.front();
    	        }
    	     }
    		    
    		 return ans;
		   
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
