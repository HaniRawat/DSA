Intuition:
We need to find the length of the longest subsequence in a given string that is also a palindrome. A subsequence is a sequence of characters from the original string, not necessarily contiguous, but maintaining their relative order. So, if a string's subsequence is a palindrome that means it reads the same forward and backwards.

We can observe that if a palindromic subsequence exists in a string then it must exist in the reverse of the string as well.

Example:

string A = "character"

string rev = "retcarahc"

Longest palindromic subsequence in A = "carac"
Longest palindromic subsequence in rev = "carac"

So, all we need to do is find the Longest common subsequence (LCS) of the two strings 'A' and 'rev'.

//Memoization

class Solution{
  public:
  
    int f(int i, int j, string A, string rev, vector<vector<int>>& dp){
        if(i<0 || j<0)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(A[i] == rev[j])
            return dp[i][j] =  1 + f(i-1, j-1, A, rev, dp);
        else
            return dp[i][j] = max(f(i, j - 1, A, rev, dp), f(i - 1, j, A, rev, dp));
    }
    int longestPalinSubseq(string A) {
        int n = A.size();
        string rev = A;
        reverse(rev.begin(), rev.end());
        
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return f(n-1, n-1, A, rev, dp);
    }
};

//Tabulation
int longestPalinSubseq(string A) {
        int n = A.size();
        string rev = A;
        reverse(rev.begin(), rev.end());
        
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(A[i-1] == rev[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
        
    }

    //space optimization
    int longestPalinSubseq(string A) {
        string rev = A;
        reverse(rev.begin(), rev.end());
        int n = A.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(A[i-1] == rev[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(curr[j-1],prev[j]);
            }
            prev = curr;
        }
        return prev[n];
    }