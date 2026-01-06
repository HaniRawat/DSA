//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int i, string op, vector<string>&res, string ip){
        if(i == ip.size()-1){
            op += ip[i];
            res.push_back(op);
            return;
        }
        
        solve(i+1, op+ip[i]+" ",res,ip);
        solve(i+1, op+ip[i],res,ip);
    }

    vector<string> permutation(string s) {
        vector<string>res;
        string op = "";
        solve(0,op,res,s);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    }
}

// } Driver Code Ends