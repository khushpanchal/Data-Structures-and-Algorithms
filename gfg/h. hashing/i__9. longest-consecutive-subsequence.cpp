//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    //Q. https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int, int> mp;
      for(int i=0; i<N; i++) mp[arr[i]] = 0;
      
      int curr = 1;
      int ans = 0;
      
      for(int i=0; i<N; i++) {
          if(mp[arr[i]]==1) continue;
          int x = arr[i]+1;
          while(mp.find(x) != mp.end() && mp[x]==0) {
              mp[x]=1;
              curr++;
              x++;
          }
          x = arr[i]-1;
          while(mp.find(x) != mp.end() && mp[x]==0){
              mp[x]=1;
              curr++;
              x--;
          }
          ans = max(ans, curr);
          curr=1;
      }
      
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends