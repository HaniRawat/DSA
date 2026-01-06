//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int fun(int n, int k, vector<vector<int>> &dp)
    {
        if(n==0 || k==0)
            return 0;
        if(n==1)
            return k;
        
        if(dp[n][k]!=-1)
            return dp[n][k];
        
        int minCost=INT_MAX;
        for(int f=1; f<=k; f++)
        {
            int a = fun(n-1, f-1, dp); // egg breaks so we need to check on floors below f i.e f-1
            int b = fun(n, k-f, dp); // egg doesnt break so we need to check on floors above f i.e. k-f
            int cost = max(a, b);
            minCost = min(minCost, cost);
        }
        return dp[n][k] = 1+minCost;
    }
    
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        return fun(n, k, dp);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends