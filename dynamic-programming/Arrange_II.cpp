int cost(string A, int l, int r) {

    int w_h = 0;
    int b_h = 0;

    for (int i = l; i <= r; i++) {

        if (A[i] == 'W')
            w_h++;
        else if (A[i] == 'B')
            b_h++;
    }
    return w_h * b_h;
}



int helper(string A, int l, int r, int B, vector<vector<int>>& dp) {

    if (l >= r)
        return 0;

    if (B == 1)
        return cost(A, l, r);

    int &ans = dp[l][B];

    if (ans != INT_MAX)
        return ans;

    for (int i = l; i < r; i++) {

        int curr_cost = 0;
        curr_cost += cost(A, l, i) + helper(A, i+1, r, B-1, dp);
        ans = min(ans, curr_cost);
    }
    return ans;
}

int Solution::arrange(string A, int B) {

    int n = A.size();
    if (n < B) return -1;
    
    vector<vector<int>> dp(n+1, vector<int>(B+1, INT_MAX));
    
    return helper(A, 0, n-1, B, dp);
}
