
//Recursion
int nCr(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    else
    {
        return (nCr(n - 1, r - 1) + nCr(n - 1, r))%mod;
    }
}

//memoization
int solve(int n, int r,vector<vector<int>> &dp){
        if(r == 0 || r == n){
            return 1;
        }
        if(dp[n][r] != -1)
            return dp[n][r];
        return dp[n][r] = (solve(n-1,r-1,dp)+solve(n-1,r,dp))%mod;
}

//tabulation
int nCr(int n, int r){
        
        int mod = 1e9+7;
        
        if(r>n)return 0;
        
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= r; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
        }
        return dp[n][r]%mod;
}