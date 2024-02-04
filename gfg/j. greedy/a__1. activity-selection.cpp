//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    static bool sortbysec(pair<int,int> a,
                  pair<int,int> b)
    {
        return (a.second < b.second);
    }
    
    //Q. https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1 
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++) {
            vec.push_back(make_pair(start[i],end[i]));
        }
        
        sort(vec.begin(), vec.end(), sortbysec);
        
        int ans = 1;
        int cs = vec[0].first;
        int ce = vec[0].second;
        
        for(int i=1; i<n; i++) {
            if(vec[i].first>ce) {
                ans++;
                cs = vec[i].first;
                ce = vec[i].second;
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends