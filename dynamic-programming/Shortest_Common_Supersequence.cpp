//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    int solve(string &s1, string &s2, int i, int j,
    vector<vector<int>> &dp){
        
        if(i>=s1.size() || j>=s2.size())
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(s1[i] == s2[j])
            return dp[i][j] = 1+solve(s1, s2, i+1, j+1, dp);
            
        return dp[i][j] = max(solve(s1, s2, i + 1, j, dp),
        solve(s1, s2, i, j + 1, dp));
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        int lcs = solve(X,Y,0,0,dp);
        return m+n-lcs;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends