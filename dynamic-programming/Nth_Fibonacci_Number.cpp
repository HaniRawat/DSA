//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        if(n <= 1)
            return n;
        
        int first = 1;
        int second = 1;
        
        const int mod = 1e9 + 7;
        
        for(int i=3; i<=n; i++){
            int temp = first+second;
            first = second;
            second = temp%mod;
        }
        
        return second;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends