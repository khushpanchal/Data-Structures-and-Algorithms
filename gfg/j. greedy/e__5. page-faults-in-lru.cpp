//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
//Q. https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1
    int pageFaults(int N, int C, int pages[]){
        // code here
        int pageFault=0;
        deque<int> dq;
                
        for(int i=0;i<min(C,N);i++)
        {   
            auto itr=find(dq.begin(),dq.end(),pages[i]);
            if(itr!=dq.end())
            {
                dq.erase(itr);
                dq.push_back(pages[i]);  
            }
            else
            {   
                pageFault++;
                dq.push_back(pages[i]);
            }
        }
    
        if(C>=N) return pageFault;
        
        for(int i=C;i<N;i++)
        {
            auto itr=find(dq.begin(),dq.end(),pages[i]);
            
            if(itr!=dq.end())
            {
                dq.erase(itr);
                dq.push_back(pages[i]);
            }
            else
            {   
                pageFault++;
                
                if(dq.size()<C) 
                {
                    dq.push_back(pages[i]);
                }
                else
                {   
                    dq.push_back(pages[i]);
                    dq.pop_front();
                }
            }
        }
        
        
        return pageFault;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends