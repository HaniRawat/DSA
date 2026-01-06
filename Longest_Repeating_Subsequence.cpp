//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int memoization(int i, int j, string& str, string& txt, vector<vector<int>>&dp){
	        if(i<0 || j<0)
	            return 0;
	            
	       if(dp[i][j] != -1)
	        return dp[i][j];
	        
	       if(str[i] == str[j] && i!=j){
	           return dp[i][j] = 1+memoization(i-1,j-1,str,txt,dp);
	       }
	       
	       return dp[i][j] = max(memoization(i-1,j,str,txt,dp),
	       memoization(i,j-1,str,txt,dp));
	    }
		int LongestRepeatingSubsequence(string str){
		    //memoization
		    
		  //  int n = str.size();
		  //  string txt(str.begin(), str.end());
		  //  vector<vector<int>>dp(n, vector<int>(n,-1));
		  //  return memoization(n-1,n-1,str,txt,dp);
		  
		  //tabulation
		  
		  int n=str.size();
		  string txt(str.begin(), str.end());
// 		  vector<vector<int>>dp(n+1, vector<int>(n+1));
		  
// 		  for(int i=1; i<=n; i++){
// 		      for(int j=1; j<=n; j++){
// 		          if(str[i-1] == txt[j-1] && i!=j){
// 		              dp[i][j] = 1+dp[i-1][j-1];
// 		          }
// 		          else{
// 		              dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
// 		          }
// 		      }
// 		  }
		  
// 		  return dp[n][n];

//SPACE OPTIMIZATION
//Whenever you see something like dp[i-1][j] or dp[i][j-1] there is a possibility to space optimize it by simply considering two rows instead of full table n+1 x n+1
            vector<int>prev(n+1), curr(n+1);
            
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(str[i-1] == txt[j-1] && i!=j){
                        curr[j] = 1 + prev[j-1];
                    }
                    else{
                        curr[j] = max(prev[j], curr[j-1]);
                    }
                }
                prev = curr;
            }
            return prev[n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends