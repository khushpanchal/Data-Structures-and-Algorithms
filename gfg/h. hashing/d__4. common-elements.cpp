//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

//Q. https://www.geeksforgeeks.org/problems/common-elements5420/1
class Solution{
    public:
    vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        // Your code here
        unordered_map<int, pair<int,int>> mp; //number, (freq in v1, freq in v2)
        for(int i=0; i<v1.size(); i++) mp[v1[i]].first++;
        for(int i=0; i<v2.size(); i++) mp[v2[i]].second++;
        
        vector<int> ans;
        
        for(auto m: mp) {
            for(int i=0; i<min(m.second.first, m.second.second); i++) {
                ans.push_back(m.first);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int>v1(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        int m;
        cin>>m;
        vector<int>v2(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>v2[i];
        }
        Solution ob;
        vector<int>result;
        result=ob.common_element(v1,v2);
        for(auto i:result)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
}
// } Driver Code Ends