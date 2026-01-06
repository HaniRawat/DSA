//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& A) {
        
        int n = A.size();
        if(n <= 2)
            return n;
            
        int ans = 0;
        
        vector<vector<int>>dp(n, vector<int>(A[n-1]-A[0]+1, 1));
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int diff = A[j] - A[i];
                dp[j][diff] = max(dp[j][diff], dp[i][diff]+1);
                
                ans = max(ans, dp[j][diff]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.lengthOfLongestAP(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends