//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSumLis(int arr[], int n) {
        
        vector<int> dp(n, 1), hash(n);
        int sum = 0, lastIndex = 0, maxLen = 1, temp = 0;
        
        for(int i=0; i<n; i++){
            hash[i] = i;
            sum += arr[i];
            
            for(int prev = 0; prev<i; prev++){
                if(arr[i] > arr[prev] && 1 + dp[prev] >= dp[i]){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            
            if(dp[i] >= maxLen){
                maxLen = dp[i];
                lastIndex = i;
            }
        }
        temp += arr[lastIndex];
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp += arr[lastIndex];
        }
        
        return sum-temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int Arr[n];
        for (int i = 0; i < n; i++) cin >> Arr[i];
        Solution obj;
        cout << obj.maxSumLis(Arr, n) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends