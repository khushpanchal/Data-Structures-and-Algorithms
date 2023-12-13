#include <bits/stdc++.h>
using namespace std;


class Solution{
public:	

	//Q. https://www.geeksforgeeks.org/problems/count-the-triplets4615/1
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    set<int> s;
	    int ans=0;
	    for(int i=0; i<n; i++) s.insert(arr[i]);
	    
	    for(int i=0; i<n; i++) {
	        for(int j=i+1; j<n; j++) {
	            if(s.find(arr[i]+arr[j]) != s.end()) {
	                ans++;
	            }
	        }
	    }
	    
	    return ans;
	    
	}
};


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}