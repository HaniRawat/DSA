bool contains(string A, vector<string>&B){
    for(int i=0; i<B.size(); i++){
        if(A.compare(B[i]) == 0)
            return true;
    }
    
    return false;
}

bool solve(string A, vector<string>&B, int index, vector<int>&dp){
    if(index == A.length())
        return true;
    
    if(dp[index] != -1)
        return dp[index];
        
        for(int i=index; i<A.length(); i++){
            if(contains(A.substr(index, i-index+1), B) && solve(A,B,i+1,dp))
                return dp[index] = true;
        }
        
        return dp[index] = false;
}

int Solution::wordBreak(string A, vector<string> &B) {
    int n = A.size();
    vector<int>dp(n+1, -1);
    return solve(A,B,0,dp);
}