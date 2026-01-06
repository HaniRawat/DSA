//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(vector<vector<int>> &matrix, int n, int i, int j){
        
        if(i>=n || j>=n || j<0 || i<0)
            return 0;
            
        int right = 0;
        if(j+1 < n && i+1 < n){
            right = solve(matrix, n, i+1, j+1);
        }
        
        int down = 0;
        if(i+1 < n){
            down = solve(matrix, n, i+1, j);
        }
        
        int left = 0;
        if(i+1 < n && j-1 >= 0){
            left = solve(matrix, n, i+1, j-1);
        }
        
        return matrix[i][j]+max(right,max(left, down));
    }
    
    int solveMemo(vector<vector<int>> &matrix, int n, int i, int j,
    vector<vector<int>> &dp){
        
        if(i>=n || j>=n || j<0 || i<0)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int right = 0;
        if(j+1 < n && i+1 < n){
            right = solveMemo(matrix, n, i+1, j+1, dp);
        }
        
        int down = 0;
        if(i+1 < n){
            down = solveMemo(matrix, n, i+1, j, dp);
        }
        
        int left = 0;
        if(i+1 < n && j-1 >= 0){
            left = solveMemo(matrix, n, i+1, j-1, dp);
        }
        
        return dp[i][j] = matrix[i][j] + max(right,max(left, down));
    }
    
    int solveTabu(vector<vector<int>> &matrix){
        
    int n=matrix.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int right=0;
            if(i+1<n && j+1<n){
                right=dp[i+1][j+1];
            }
            int down=0;
            if(i+1<n){
                down=dp[i+1][j];
            }
            int left=0;
            if(i+1<n && j-1>=0){
                left=dp[i+1][j-1];
            }

            dp[i][j]= matrix[i][j]+max(right,max(left,down));
        }
    }
  int maxi=0;
  for(int i=0;i<n;i++){
    maxi=max(maxi,dp[0][i]);
  }

    return maxi;
}
    
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // return solve(matrix, n, 0, 0);
        // vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        // solveMemo(matrix,n, 0, 0, dp);
        
        solveTabu(matrix);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends