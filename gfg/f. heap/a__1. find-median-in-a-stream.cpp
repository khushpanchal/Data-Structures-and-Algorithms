//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Q. https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
class Solution
{
    public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(max_heap.size()==0 || max_heap.top()>x) {
            max_heap.push(x);
        } else {
            min_heap.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top()); min_heap.pop();
            
        } else if(max_heap.size() > min_heap.size()+1) {
            min_heap.push(max_heap.top()); max_heap.pop();
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        double median;
        
        if(min_heap.size() == max_heap.size()) {
            median = (min_heap.top() + max_heap.top()) / 2.0;
        } else if(min_heap.size() > max_heap.size()) {
            median = min_heap.top();
        } else {
            median = max_heap.top();
        }
        
        return median;
        
    }
};



//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends