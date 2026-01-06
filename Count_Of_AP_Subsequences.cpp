//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int count(vector<int>& A) {
        
        int N = A.size();
        vector<vector<int>> dp(N+1,vector<int>(201,0));
        
        long long int res= 1;
        
        for(int i = 0;i<N;i++){
            for(int j = 0;j<i;j++){
                
                int diff = A[i] - A[j] + 100;
                dp[i][diff] += 1 + dp[j][diff];
                res+= dp[j][diff] + 1;
            }
        }
        return res + N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends