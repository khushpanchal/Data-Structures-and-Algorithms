//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
 

class Solution{
    public:
    
    double convert(int x)
    {
        //x^y > y^x
        //ylogx > xlogy
        //logx/x > logy/y
        return log(x)/(x);
    }
    
    //https://www.geeksforgeeks.org/problems/number-of-pairs-1587115620/1
    // X[], Y[]: input array
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int M, int N)
    {
       //Your code here
        double X_arr[M];
        double Y_arr[N];

        for (int i=0; i<M; i++) {
            X_arr[i] = convert(X[i]);
        }

        for (int i=0; i<N; i++) {
            Y_arr[i] = convert(Y[i]);
        }

        sort(X_arr, X_arr + M);
        sort(Y_arr, Y_arr + N);

        long long ans = 0;
        int j = 0;

        for (int i=0; i<M; i++) {
            while (j<N && X_arr[i]>Y_arr[j]) {
                j++;
            }
            ans += j;
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}
// } Driver Code Ends