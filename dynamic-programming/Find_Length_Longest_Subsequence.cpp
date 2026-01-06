//memoization
int solve(string &X, string &Y, int m, int n, vector < vector <int> > &dp) {
    if(m == 0 || n == 0)
        return 0;
    if(dp[m][n] != -1)
        return dp[m][n];
    int count1 = 0, count2, ans;
    if(X[m - 1] == Y[n - 1])
        count1 = 1 + solve(X, Y, m - 1, n - 1, dp);
    count2 = solve(X, Y, m - 1, n, dp);
    ans = max(count1, count2);
    return dp[m][n] = ans;
}

int maxSubsequenceSubstring(string X, string Y, int N, int M) {
    vector < vector <int> > dp(N + 1, vector <int>(M + 1, -1));
    int maxi = INT_MIN;
    for(int i = M - 1; i >= 0; i--) {
        maxi = max(maxi, solve(X, Y, N, i + 1, dp));
    }
    
    return maxi;
 
}

//tabulation
int maxSubsequenceSubstring(string X, string Y, int N, int M){
    vector < vector <int> > dp(N + 1, vector <int>(M + 1, 0));
    
    for(int i = 1; i < N + 1; i++)
        for(int j = 1; j < M + 1; j++) {
            if(X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j];
        }
    return *max_element(dp[N].begin(), dp[N].end());
}

//iterative
int maxSubsequenceSubstring(string X, string Y, int N, int M) {
    int maxi = 0;
    for(int i = 0; i < M; i++) {
        int cnt = 0, j = i;
        for(auto x: X)
            if(x == Y[j]) {
                cnt++;
                j++;
            }
        maxi = max(maxi, cnt); 
    }
  return maxi;
}