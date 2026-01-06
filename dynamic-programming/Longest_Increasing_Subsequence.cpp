//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int longestIncreasingSubsequence(int ind, int prevInd,
    vector<int> &arr, vector<vector<int>> &dp){
        
        if(ind < 0)
            return 0;
            
        int take = -1e8;
        int notTake = longestIncreasingSubsequence(ind-1, prevInd, arr, dp);
        
        if(dp[ind][prevInd] != -1)
            return dp[ind][prevInd];
            
        if(prevInd== arr.size())
            take = 1 + longestIncreasingSubsequence(ind-1, ind, arr, dp);
            
        else if(arr[ind] < arr.at(prevInd))
            take = 1 + longestIncreasingSubsequence(ind-1, ind, arr, dp);
            
        return dp[ind][prevInd] = max(take, notTake);
    }
    //Function to find length of longest increasing subsequence.
    // int longestSubsequence(int n, int a[])
    // {
    // //   vector<int> arr(a , a+n);
    // //   vector<vector<int>> dp(n, vector<int>(n+1, -1));
      
    // //   return longestIncreasingSubsequence(n-1, n, arr, dp);
    
    // vector<int> dp(n, 1);
    //     int maxi = 1;
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (a[j] < a[i] && 1 + dp[j] > dp[i])
    //             {
    //                 dp[i] = 1 + dp[j];
    //             }
    //         }
    //         maxi = max(maxi, dp[i]);
    //     }
    //     return maxi;
    // }
    
    int longestSubsequence(int n, int a[])
    {
        //Binary Search
        int maxi = 1;
        vector<int> dp; 
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(dp.begin(), dp.end(), a[i]);
            if (it == dp.end())
            {
                dp.emplace_back(a[i]);
            }
            else
            {
                int ind = it - dp.begin();
                dp.at(ind) = a[i];
            }
            maxi = max(maxi, (int)dp.size());
        }
        return maxi;
    }

};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends