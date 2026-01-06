//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the total number of possible unique BST.

    // The number of ways would be:

    //     1. choose one node as root
    //     2. choose M nodes as part of the left subtree
    //     3. right subtree would be left with N-1-M nodes.
    //     4. Go to steps one until we left with one nodes(only one way).
    //     => [{0,ROOT,N-1}, {1,ROOT, N-2}, {2, ROOT,N-3} ...... {N-3,ROOT, 2}, {N-2,ROOT,1}, {N-1,ROOT, 0}]

    //     if we have no node or 1 node, we can create only 1 BST. 
    int numTrees(int N) 
    {
        int mod = 1e9+7;
        
        vector<long long int>dp(N+1, 0);
        dp[0] = dp[1] = 1;
        
        
        int l,r;
        
        for(int i=2; i<=N; i++){
            l = 0;
            r = i-1;
            
            while(l <= r){
                if(l < r){
                    // {0, ROOT, N-1} + {N-1, ROOT, 0} => 2*{0, ROOT, N-1} 
                    dp[i] = (dp[i] + (2*dp[l]*dp[r]) % mod) % mod;
                }else{
                    // if N is odd i.e. {2, ROOT, 2} 
                    dp[i] = (dp[i] + (dp[l]*dp[r])% mod) % mod;
                }
                l++;
                r--;
            }
        }
        return dp[N];
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    
cout << "~" << "\n";
}
}	
// } Driver Code Ends