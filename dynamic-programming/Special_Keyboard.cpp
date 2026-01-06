//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int N){
        
        if(N<=6)
            return N;
            
        vector<long long int>dp(N+1, 0);
        
        for(int i=1; i<=6; i++){
            dp[i] = i; // Option 1: Press 'A'
        }
        
        for(int i=7; i<=N; i++){
            
            // Option 2: Perform Ctrl-A, Ctrl-C, and multiple Ctrl-Vs
            for(int j=i-3; j>=1; j--){
                
                int curr = dp[j]*(i-j-1);
                // If we copy all from dp[j-2] and paste (i - j) times
                if(curr>dp[i])
                    dp[i] = curr;
            }
        }
        return dp[N];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends