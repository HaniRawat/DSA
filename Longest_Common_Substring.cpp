//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        
        int n=str1.size();
        int m=str2.size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        int ans = 0;
        
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){
                    
                    dp[i][j] = 1+dp[i-1][j-1];
                    
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;
    }
    
    Code Explanation:

// The key idea is to use a 2D DP table dp[i][j] where:

// dp[i][j] stores the length of the longest common substring that ends at str1[i-1] and str2[j-1].


// To compare substrings of two strings efficiently, we build up a solution incrementally by solving smaller subproblems.

// We can think of dp[i][j] as:

// 1)If str1[i-1] == str2[j-1], then we extend the common substring by 1, i.e., dp[i][j] = dp[i-1][j-1] + 1. This means that the current characters match, so we look at the longest common substring ending at str1[i-2] and str2[j-2] and add 1.
// 2)If str1[i-1] != str2[j-1], then the current characters don't match, so the longest common substring ending at str1[i-1] and str2[j-1] is 0, i.e., dp[i][j] = 0.


// Time complexity: O(n * m) where n is the length of str1 and m is the length of str2, since we compute the value for each pair of indices once.

// Space complexity: O(n * m) for storing the DP table.
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends