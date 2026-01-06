class Solution {
public:

    int solve(int i, int sum, vector<int>& a, vector<vector<int>>& dp ){
        if(i == -1)
            return sum;

        if(dp[i][sum] != -1)
            return dp[i][sum];
            
        return dp[i][sum] = min(solve(i-1, abs(sum-a[i]),a,dp), solve(i - 1,sum + a[i],a,dp));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int max_sum = 0;

        for(auto e : stones)
            max_sum += e;
        
        int n =  stones.size();
        vector<vector<int>>dp(n, vector<int>(max_sum+1, -1));
        return solve(n-1, 0, stones, dp);
    }
};