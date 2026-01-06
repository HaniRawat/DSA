//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    long long solve(int n, vector<long long>&dp){
                
        
        if(n <= 1)
            return n;
            
        if(dp[n] != -1)
            return dp[n];
            
        return dp[n] = solve(n-1, dp)+solve(n-2, dp);
    }
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        vector<long long> dp(n+1, -1);
        //top down approach / memoisation
        
        solve(n, dp);
        dp[0] = 0;
        dp[1] = 1;
        
        vector<long long> res;
        
        for(int i=1; i<=n; i++){
            res.push_back(dp[i]);
        }
        return res;
    }

    vector<long long> printFibb(int n) 
    {
        
        //bottom up approach / tabulation
        vector<long long> dp(n+1, -1);
        
        
        dp[0] = 0;
        dp[1] = 1;
        
        
        
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        vector<long long> res;
        for(int i=1; i<=n; i++){
            res.push_back(dp[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends