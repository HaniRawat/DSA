int Solution::solve(vector<vector<int> > &A) {

    if (A.size() == 1) {
        return *max_element(A[0].begin(), A[0].end());
    }

    int ans = 0;
    vector<vector<int>>dp = A;

    for (int i=1;i<A.size();i++) {
        for (int j=0;j<=i;j++) {

            if (i>0 && j>0) {
                dp[i][j] = max(dp[i][j], A[i][j] + dp[i-1][j-1]);
            }
            if (j < i) {
                dp[i][j] = max(dp[i][j], A[i][j] + dp[i-1][j]);
            }
            if (i == (A.size()-1)) {
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}
