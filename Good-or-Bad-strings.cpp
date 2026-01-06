//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int isGoodorBad(string S) {
        int cntV = 0;
        int cntC = 0;

        int n = S.length();

        for (int i = 0; i < n; i++) {
            if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' ) {
                cntV++;
                cntC = 0;
            } else if( S[i] == '?'){
                cntV++;
                cntC++;
            }
            else{
                cntC++;
                cntV = 0;
                
            }
            
            if(cntV > 5 || cntC > 3){
                return 0;
            }
            
        }
          return 1;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        
        cin >> S;
        
        Solution ob;
        cout << ob.isGoodorBad(S) << endl;
    }
    return 0; 
}
// } Driver Code Ends