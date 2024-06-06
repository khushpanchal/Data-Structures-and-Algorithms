//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  //Q. https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int i=0; i<n; i++) freq[nums[i] % k]++;

        for (int i=0; i<n; i++) {
            int rem = nums[i] % k;

            // If half of k exists even number of times
            if (rem == k-rem) {
                if (freq[rem] % 2 != 0) return false;
            }
            // even no. of 0's
            else if (rem == 0) {
                if (freq[rem] % 2 != 0) return false;
            }
            else if (freq[rem] != freq[k - rem])
                return false;
        }
        return true;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends