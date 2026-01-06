//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
  public:
    int subsequenceCount(string s, string t) {
        
        int n = s.size(), m = t.size();
        vector<int> prev(m+1, 0);
        
        for(int i=1; i<=n; i++){
            
            prev[0] = 1;
            
            for(int j=m; j>=1; j--){
                
                int mod = 1e9+7;
                
                if(s[i-1] == t[j-1])
                    prev[j] = (prev[j-1]+prev[j]) % mod;
            }
        }
        return prev[m];
    }
};


//{ Driver Code Starts.

//  Driver code to check above method
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        string tt;
        cin >> s;
        cin >> tt;

        Solution ob;
        cout << ob.subsequenceCount(s, tt) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends