//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends

//Q. https://www.geeksforgeeks.org/problems/find-first-repeated-character4108/1
string firstRepChar(string s)
{
    //code here.
    int h[26]={0};
    bool flag=false;
    string res;
    for(int i=0;i<s.length();i++)
    {
        if(h[s[i]-'a']>=1)
        {
            res = s[i];
            flag=true;
            break;
        }
        else
            h[s[i]-'a']++;
    }
    if(flag==false)
        res = "-1";
        
    return res; 
}