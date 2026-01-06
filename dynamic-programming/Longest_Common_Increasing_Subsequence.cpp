//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int LCIS(const vector<int>& arr1, const vector<int>& arr2) {
        
        int m=arr1.size(), n=arr2.size();
        int dp[n];
        for (int j = 0; j < n; j++) dp[j] = 0;
        for (int i = 0; i < m; i++) {
            int current = 0;
            for (int j = 0; j < n; j++) {
                if (arr1[i] == arr2[j]) {
                    if (current + 1 > dp[j]) {
                        dp[j] = current + 1;
                    }
                }
                if (arr1[i] > arr2[j]) {
                    if (dp[j] > current) {
                        current = dp[j];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr1, arr2;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the first array elements
        stringstream ss1(input1);
        int number;
        while (ss1 >> number) {
            arr1.push_back(number);
        }

        getline(cin, input2); // Read the entire line for the second array elements
        stringstream ss2(input2);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        int result = ob.LCIS(arr1, arr2);

        cout << result << endl;
    }
    return 0;
}

// } Driver Code Ends