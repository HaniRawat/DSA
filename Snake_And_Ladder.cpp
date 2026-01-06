//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    #define goal 30
    
    int minThrow(int N, int arr[]){
        
        unordered_map<int,int>map;
        vector<int>dp(goal+1, INT_MAX);
        
        dp[1] = 0; /// It takes 0 dice throws to start at position 1
        
        for(int i=0; i<2*N; i+=2){
            map[arr[i]] = arr[i+1];
        }
        
        for(int i=1; i<=goal; i++){
            if(dp[i] == INT_MAX)
                continue; // If this position is unreachable, skip it
                
            for(int dice = 1; dice<=6; dice++){
                if(i+dice <= goal){
                    int next = i+dice;
                        
                    if(map.find(next) != map.end()){
                        next = map[next]; //jump due to snake or ladder
                    }
                    dp[next] = min(dp[next], dp[i]+1);
                }
            }
        }
        return dp[goal] == INT_MAX ? -1 : dp[goal];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends