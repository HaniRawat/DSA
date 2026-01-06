//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int minCoins(vector<int> &coins, int target) {
        
        int n = coins.size();
        vector<int>prev(target+1,0),curr(target+1,0);
        for(int i=1;i<=target;i++){
            prev[i]=1e9;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                int take = 1e9;
                if(coins[i-1]<=j){
                    take = 1 + curr[j-coins[i-1]];
                }
                int skip = prev[j];
                curr[j] = min(take,skip);
            }
            prev=curr;
        }
        return prev[target]==1e9?-1:prev[target];
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends