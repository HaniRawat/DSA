//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        
        
        vector<vector<long long>>dp(n,vector<long long>(3));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0)dp[i][j] = r[i];
                else if(j==1)dp[i][j] = g[i];
                else dp[i][j] = b[i];
            }
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0)
                {
                    dp[i][j] += min(dp[i-1][j+1],dp[i-1][j+2]);
                }
                else if(j==1)
                {
                   dp[i][j] += min(dp[i-1][j-1],dp[i-1][j+1]);
                }
                else
                {
                   dp[i][j] += min(dp[i-1][j-1],dp[i-1][j-2]);
                }
            }
        }
        long long ans;
        ans=min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends