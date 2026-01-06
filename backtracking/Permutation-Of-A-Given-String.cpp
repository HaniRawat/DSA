//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    
	    void solve(string s, int start, set<string>& ans){
	        if(start == s.length()-1){
	            ans.insert(s);
	            return;
	        }
	        
	        for(int i=start; i<s.length(); i++){
	            swap(s[start], s[i]);
	            solve(s,start+1,ans);
	            swap(s[start], s[i]);
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    set<string>ans;
		    solve(s,0,ans);
		    return vector<string>(ans.begin(), ans.end());
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends