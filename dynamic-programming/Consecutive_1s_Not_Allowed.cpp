//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    
	    vector<long>dp(n+1, 0);
	    int mod = 1e9 + 7;
	    
	    dp[0] = 1;
	    
	    for(int i=1; i<=n; i++){
	        
	        long pick = (i > 1 ? dp[i-2] : 1);
	        long notPick = dp[i-1] % mod;
	        
	        dp[i] = (pick + notPick) % mod;
	    }
	    
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends