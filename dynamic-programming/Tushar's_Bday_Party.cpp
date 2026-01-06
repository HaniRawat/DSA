int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int ans = 0;
    
    int n=A.size();
    int m=B.size();
    int target = *max_element(A.begin(),A.end());
    
    //DP table to store min cose for each capacity
    vector<int>dp(target+1, 1e9);
    dp[0] = 0; //cost of achieving 0 capacity is 0
    
    //fill the dp array for each capacity from 1 to target
    for(int i=0; i<m; i++){
        for(int capacity=B[i]; capacity<=target; capacity++){
            dp[capacity] = min(dp[capacity], dp[capacity-B[i]]+C[i]);
        }
    }
    
    for(int a: A){
        ans += dp[a];
    }
    return ans;
}