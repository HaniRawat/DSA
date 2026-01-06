int Solution::maxProfit(const vector<int> &a) {
    int n=a.size();
    if(n==0)return 0;
    vector<vector<int>>dp0(2,vector<int>(3));
    vector<vector<int>>dp1(2,vector<int>(3));
    for(int i=0;i<=2;i++)
    {
        dp1[(n-1)%2][i]=0;
    }
    dp0[(n-1)%2][0]=0;
    dp0[(n-1)%2][1]=a[n-1];
    dp0[(n-1)%2][2]=a[n-1];
    for(int i=0;i<n;i++)
    {
        dp0[i%2][0]=0;
        dp1[i%2][0]=0;
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=1;j<=2;j++)
        {
            dp1[i%2][j]=max(-a[i]+dp0[(i+1)%2][j],dp1[(i+1)%2][j]);
            dp0[i%2][j]=max(a[i]+dp1[(i+1)%2][j-1],dp0[(i+1)%2][j]);
        }
    }
    return dp1[0%2][2];
}