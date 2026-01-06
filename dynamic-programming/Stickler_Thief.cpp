//  int solve(int nums[], int n, int index,  vector<int> &dp){
//         if(index >= n) return 0;
        
//         if(dp[index] != -1) return dp[index];
        
//         int op1 = nums[index] + solve(nums, n, index+2, dp);
//         int op2 = 0 + solve(nums, n, index+1, dp);
//         dp[index] = max(op1, op2);
//         return dp[index];
//     }

    int solveTab(int arr[],int n)
    {
        vector<int> dp(n,0);
        dp[0] =arr[0];
        
        for(int i=1;i<n;i++)
        {
            int incl = dp[i-2] + arr[i];
            int excl = dp[i-1] +0;
            dp[i] = max(incl,excl);
        }
        
        return dp[n-1];
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // vector<int> dp(n+1, -1);
        // int ans = solve(arr, n, 0, dp);
        vector<int> dp(n,-1);
        return solveTab(arr,n);
    }