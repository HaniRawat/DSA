//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	int countSubstringWithEqualEnds(string s)
	{
	    map<int,int>mp;
	    
	    int ans = 0;
	    int n = s.size();
	    
	    for(int i=0; i<n; i++)
	        mp[s[i]]++;
	        
	    for(auto it : mp){
	        if(it.second > 1){
	            int x = it.second;
	            ans += (x*(x-1))/2;
	        }
	    }
	    ans += n;
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   	    Solution ob;

   		cout << ob.countSubstringWithEqualEnds(str) << "\n";
   	}

    return 0;
}
// } Driver Code Ends