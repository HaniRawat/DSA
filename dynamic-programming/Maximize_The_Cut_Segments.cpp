class Solution
{
    public:
    //Function to find the maximum number of cuts.
    //solving with recurrsion
int solve(int n,int x,int y,int z,vector<int> &dp){
    //base case
    if(n<0){
        return INT_MIN;
    }

    if(n==0){
        return 0;
    }
    
    if(dp[n]!=INT_MIN){
        return dp[n];
    }

    int xans=1+solve(n-x,x,y,z,dp);
    int yans=1+solve(n-y,x,y,z,dp);
    int zans=1+solve(n-z,x,y,z,dp);

    dp[n]= max(xans,max(yans,zans));
    return dp[n];
}

//using tablutaation method;
int solveTablutation(int n,int x,int y,int z){
    vector<int> dp(n + 1, -1); // Use -1 to indicate that a value hasn't been computed yet
    dp[0] = 0; // Base case: 0 length requires 0 segments

    for (int i = 1; i <= n; i++) {
        int xans = (i - x >= 0 && dp[i - x] != -1) ? 1 + dp[i - x] : -1;
        int yans = (i - y >= 0 && dp[i - y] != -1) ? 1 + dp[i - y] : -1;
        int zans = (i - z >= 0 && dp[i - z] != -1) ? 1 + dp[i - z] : -1;

        dp[i] = max({xans, yans, zans});
    }

    return dp[n] == -1 ? 0 : dp[n];
}
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //vector<int> dp(n+1,INT_MIN);
    int ans=solveTablutation(n,x,y,z);
    if(ans<=0){
        return 0;
    }
    return ans;
    }
};