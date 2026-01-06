//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int a[], int n, int k) {
        int ans = INT_MAX ; 
        sort(a,a+n) ;
        
        vector<int> ps(n) ;
        ps[0] = a[0] ;
        for(int i=1 ; i<n ; i++)
            ps[i] = a[i] + ps[i-1] ;

        for(int i=0 ; i<n ; i++){
            int fui = upper_bound(a,a+n,a[i]+k)-a ;
            ans = min(ans, (i>0 ? ps[i-1] : 0) + ps[n-1]-(fui>0 ? ps[fui-1] : 0) - (n-fui)*(a[i]+k)) ;
        }
        return ans ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends