//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
    public:
    static bool comp(vector<int>A,vector<int>B)
    {
        return (A[1]*A[2])>(B[1]*B[2]);
    }
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    
    //Q https://www.geeksforgeeks.org/problems/box-stacking/1
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        vector<vector<int>>boxs(3*n,vector<int>(3,0));
        
        for(int i=0,j=0;i<n;i++)
        {   int h=height[i],w=width[i],l=length[i];
            boxs[j][0]=h;
            boxs[j][1]=max(l,w);
            boxs[j][2]=min(l,w);
            j++;
                
            boxs[j][0]=w;
            boxs[j][1]=max(l,h);
            boxs[j][2]=min(l,h);
            j++;
                
            boxs[j][0]=l;
            boxs[j][1]=max(h,w);
            boxs[j][2]=min(h,w);
            j++;
        }
        
        sort(boxs.begin(),boxs.end(), comp);
    
        int dp[3*n],ans=0;
    
        for(int i=0;i<3*n;i++)
        {   
            int h=boxs[i][0];
            dp[i]=h;
            for(int j=0;j<i;j++)
            {  
                int w=boxs[j][1], d=boxs[j][2];
                if(w>boxs[i][1]&&d>boxs[i][2])
                    dp[i]=max(dp[j]+h,dp[i]);
            }
        }
    
        for(int i=0;i<3*n;i++)
            ans=max(ans,dp[i]);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	
// } Driver Code Ends