//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void solve(int index, int open, int close, vector<string>& ans, string curr, int n){
    if(index >= n*2){
        ans.push_back(curr);
        return;
    }
    
    if(open < n){
        curr += '(';
        solve(index+1, open+1, close,ans,curr,n);
        curr.pop_back();
    }
    
    if(close < open){
        curr += ')';
        solve(index+1, open, close+1, ans, curr, n);
        curr.pop_back();
    }
}

    vector<string> AllParenthesis(int n) 
    {
    int open = 0, close = 0, index = 0;
    vector<string>ans;
    string curr;
    
    solve(index, open, close, ans, curr, n);
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends