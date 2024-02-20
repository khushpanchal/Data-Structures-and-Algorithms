//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }

    //Q. https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end(), cmp);
        int k = 0, j = 1, cnt = 1;
        while(j < n) {
            if(v[k].second < v[j].first) {
                cnt++;
                k = j;
                j++;
            }
            else
            j++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends