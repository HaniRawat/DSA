//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i=0, j=0;
        
        while(i < S.length() && j < T.length()){
            if(isdigit(T[j])){
                int cnt = 0;
                while(j < T.length() && isdigit(T[j])){
                    cnt = cnt*10 + (T[j]-'0');
                    j++;
                }
                i += cnt;
            }
            else{
                if(S[i] != T[j])
                    return 0;
                i++;
                j++;
            }
        }
        
        return i == S.length() && j == T.length();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends