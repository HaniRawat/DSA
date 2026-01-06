// BRUTE FORCE
    // int countWays(int n)
    // {
    //     if(n<0) return 0;
    //     if(n==0){
    //         return 1;
    //     }
    //     int one_step = countWays(n-1);
    //     int two_step = countWays(n-2);
    //     return one_step+two_step;
    // }

// MEMOIZATION
    // int countWays(int n)
    // {
    //     int dp[] = new int[n+1];
    //     Arrays.fill(dp,-1);
    //     return count(n,dp);
    // }
    // int count(int n,int dp[])
    // {
    //     if(n<0) return 0;
    //     if(n==0){
    //         return 1;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     int one_step = count(n-1,dp);
    //     int two_step = count(n-2,dp);
    //     return dp[n]= (one_step+two_step)%1000000007;
    // }

 // TABULATION
    // int countWays(int n)
    // {
        // if(n==0 || n==1) return 1;
        // int dp[] = new int[n+1];
        // dp[0] = 1;
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i] = (dp[i-1]+dp[i-2])%1000000007;
        // }
        // return dp[n];
        
    // }

// SPACE OPTIMISATION 
    int countWays(int n)
    {
         if(n==0 || n==1) return 1;
        int prev = 1,curr=1;
        for(int i=2;i<=n;i++){
            int temp = curr;
            curr = (prev+curr)%1000000007;
            prev = temp;
        }
        return curr;
    }