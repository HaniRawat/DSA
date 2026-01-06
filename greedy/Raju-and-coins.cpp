//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
public:
    int maxNumbers(int n, int k, int a[]){
       int count = 1;
       int sum = 0;
       int ans = 0;
       
       sort(a,a+n);
       
       int i = 0;
       while(sum < k){
           if(count != a[i]){
               sum += count;
               ans++;
               count++;
           }else{
               count++;
               i++;
           }
       }
       return ans-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int a[n];
        for(int i = 0; i < n; i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.maxNumbers(n, k, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends