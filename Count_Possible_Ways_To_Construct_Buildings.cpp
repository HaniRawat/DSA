//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod = 1e9+7;
	
	long long solve(int places, int val)
    {
    
        int pre0 = 1;
        int pre1 = 1;
    
        for (int i = 2; i <= places; i++)
        {
            int cur0 = pre1 % mod;
            int cur1 = (pre0 % mod + pre1 % mod) % mod;
    
            pre0 = cur0;
            pre1 = cur1;
        }
    
        return pre0 % mod + pre1 % mod;
    }
	
	int TotalWays(int N)
	{
	    long long ans = solve(N, 0) % mod;
        return ((ans % mod) * (ans % mod))%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends