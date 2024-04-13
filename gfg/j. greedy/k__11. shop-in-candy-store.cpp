//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
//Q. https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies, candies+N);
        int minAmount = 0;
        int maxAmount = 0;
        
        int j=N;
        
        for(int i=0; i<j; i++) {
            minAmount += candies[i];
            j-=K;
        }
        
        j=0;
        
        for(int i=N-1; i>=j; i--) {
            maxAmount += candies[i];
            j+=K;
        }
        
        return {minAmount, maxAmount};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
