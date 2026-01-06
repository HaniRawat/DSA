//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    
    long long solve(int row,int col,int n,int k,vector<vector<int>>& arr,vector<vector<vector<int>>>& dp)
    {
        
        if(row<0 || col<0 || row>=n || col>=n || k<0)
        {
            return 0;
        }
        if(row==0 && col==0)
        {
            if(k-arr[row][col]==0)
            {
                return 1;
            }
            else
            return 0;
        }
        if(dp[row][col][k]!=-1)
        {
            return dp[row][col][k];
        }
        
        int down=solve(row-1,col,n,k-arr[row][col],arr,dp);
        int right=solve(row,col-1,n,k-arr[row][col],arr,dp);
        
        return dp[row][col][k] = down + right;
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        
        return solve(n-1,n-1,n,k,arr,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends