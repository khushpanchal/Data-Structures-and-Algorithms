#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    //Q. https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1
    int missingNumber(vector<int>& arr, int n) {
        for(int i=0; i<n-1; i++) {
            if(arr[i]-1==i || arr[i]==n) continue;
            else {
                swap(arr[arr[i]-1], arr[i]);
                i--;
            }
        }
        int ans = -1;
        for(int i=0; i<n-1; i++) {
            if(arr[i]!=i+1) {
                ans = i+1;
                break;
            }
        }
        if(ans==-1) return n;
        return ans;
    } 
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}