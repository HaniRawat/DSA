//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
   string rearrangeString(string str) {
    map<char,int> mp;
    for(int i = 0; i < str.length();i++)
            mp[str[i]]++;

     //push all char's in the pq with freq    
    priority_queue<pair<int, char>> pq;

    for(auto elem:mp)
        pq.push({elem.second,elem.first});
    
    string output(str.length(),' ');
    int index = 0;

    while(!pq.empty()){
        int first = pq.top().first;
        while(first--){
            if(index >= output.size())
                index = 1;
            
            output[index] = pq.top().second;
            index += 2;
        }
        pq.pop();
    }
    for(int i = 1; i < output.length(); i++){
        if(output[i] == output[i-1])
            return "-1";
    }
    return output;
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