//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends

//Q. https://www.geeksforgeeks.org/problems/rearrange-characters4649/1
class Solution
{
    public:
    string rearrangeString(string str)
    {
        priority_queue<pair<int, char> >pq;
        //code here
        vector<int> vec(26, 0);
        for(int i=0; i<str.length(); i++) {
           vec[str[i] - 'a']++;
        }
        
        for(int i=0; i<26; i++) if(vec[i]!=0) pq.push({vec[i], 'a'+i});
        
        string ans;
        
        pair<int, char> temp = {-1,'a'};
        
        while(!pq.empty()) {
            pair<int, char> top = pq.top();
            pq.pop();
            
            ans += top.second;
            top.first--;
            if(temp.first > 0) {
                pq.push(temp);
            }
            temp = top;
        }
        
        if(ans.length() != str.length()) return "-1";
        return ans;
        
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends