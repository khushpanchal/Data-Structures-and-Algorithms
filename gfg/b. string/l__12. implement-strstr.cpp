//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends

//Q. https://www.geeksforgeeks.org/problems/implement-strstr/1
//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
    if (x[0] == '\0') 
        return 0;
    
    for (int i = 0; s[i] != '\0'; i++) 
    {
        bool isMatched = true;
        
        for (int j = 0; x[j] != '\0'; j++) 
        {
            if(s[i + j] == 0) 
                return -1;
            
            if(s[i + j] != x[j]) {
                isMatched = false;
                break;
            }
        }
        
        if (isMatched) 
        return i;
    }
    return -1;
    //Other better solution: KMP algorithm.
}