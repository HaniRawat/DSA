//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        int c = 0;
        
        for(int i=0; i<=n; i++){
            int k=i;
            
            while(k>0){
                if(k%10 == 4){
                    c++;
                    break;
                }
                k/=10;
            }
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends