//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    // bool subsetSum(vector<int>&arr, int n, int sum){
    //     //recursive
    //     if(sum == 0)
    //         return true;
            
    //     else if(n == 0)
    //         return false;
            
    //     if(arr[n-1] > sum)
    //         return subsetSum(arr, n-1, sum);
            
    //     return (subsetSum(arr,n-1,sum-arr[n-1]) || subsetSum(arr,n-1,sum));
    // }
    
    bool subsetSum(vector<int>&arr, int n, int sum, vector<vector<int>>&dp){
        //memoization
        if(sum == 0)
            return true;
            
        if(n == 0)
            return false;
            
        if(dp[n][sum] != -1)
            return dp[n][sum];
            
        if(arr[n-1] > sum)
            return dp[n][sum] = subsetSum(arr, n-1, sum, dp);
            
        return dp[n][sum]=(subsetSum(arr,n-1,sum-arr[n-1],dp) ||
        subsetSum(arr,n-1,sum,dp));
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        // vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        // return subsetSum(arr,n,sum,dp);
        
      vector<vector<int>>dp(n+1, vector<int>(sum+1, false));
        
        for(int i=0; i<=n; i++)
            dp[i][0] = true;
            
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(arr[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends