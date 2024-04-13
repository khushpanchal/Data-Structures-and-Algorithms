//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    //Q. https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int totalPetrol = 0;
       int totalDistance = 0;
       int currPetrol = 0; //from start
       int currDistance = 0; //from start
       int start = 0;
       
       for(int i=0; i<n; i++) {
           totalPetrol += p[i].petrol;
           totalDistance += p[i].distance;
           
           currPetrol += p[i].petrol;
           currDistance += p[i].distance;
           
           if(currPetrol < currDistance) { //change the start whenever petrol gets lesser then distance
               start = i+1;
               currPetrol = 0;
               currDistance = 0;
           }
       }
       
       if(totalPetrol < totalDistance) return -1;
       else return start;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends
