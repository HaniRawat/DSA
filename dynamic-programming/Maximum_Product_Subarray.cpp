//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    // Function to find maximum product subarray
    long long maxProduct(vector<int> &arr) {
        
        long long maxi = INT_MIN;
        long long n = arr.size();
        
        for(int i=0; i<n; i++){
            long long sum = 1;
            for(int j=i; j<n; j++){
                sum *= arr[j];
                maxi = max(sum,maxi);
                
                if(sum == 0)
                    break;
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends