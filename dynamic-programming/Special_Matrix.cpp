//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    
	    int mod = 1e9+7;
	    vector<vector<int>>dp(n, vector<int>(m, -1));
	    
	    //mark all the blocked cells 0
	    for(int i=0; i<blocked_cells.size(); i++){
	        int row = blocked_cells[i][0]-1;
	        int col = blocked_cells[i][1]-1;
	        dp[row][col] = 0;
	    }
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            
	            if(dp[i][j] == 0)
	                continue;
	            
	            if(i == 0 && j == 0)
	                dp[0][0] = 1;
	                
	            else{
	                int up = 0, left = 0;
	                
	                if(i > 0)
	                    up = (dp[i-1][j])% mod;
	                if(j > 0)
	                    left = (dp[i][j-1])% mod;
	               
	               dp[i][j] = (up + left)% mod;
	            }
	        }
	    }
	    return dp[n-1][m-1];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends