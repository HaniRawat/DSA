int Solution::maximalRectangle(vector<vector<int> > &A) {

    int n= A.size();
    int m= A[0].size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(A[i][j]==0)
                dp[i+1][j+1]=0;
            else{
                dp[i+1][j+1]=1+dp[i][j+1];
            }
        }
    }
    int area= INT_MIN;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            int wid=dp[i][j];

            for(int k=j; k<=m ; k++){

                wid=min(wid, dp[i][k]);
                int tar;
                tar=(k-j+1)*wid;
                
                area=max(area, tar);
            }
        }
    }
    return area;
}

