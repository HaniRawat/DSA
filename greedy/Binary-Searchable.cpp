//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int binarySearchable(int arr[], int n) {
        
        vector<int>leftmax(n),rightmin(n);
        
       leftmax[0]=INT_MIN; 
       rightmin[n-1]=INT_MAX;
       
       for(int i=1;i<n;i++) 
        leftmax[i]=max(leftmax[i-1],arr[i-1]);
        
       for(int i=n-2;i>=0;i--)
        rightmin[i]=min(rightmin[i+1],arr[i+1]);
        
       int ans=0;
       
       for(int i=0;i<n;i++)
       {
           if(leftmax[i]<arr[i] && arr[i]<rightmin[i]) ans++;
       }
       
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int Arr[n];
        for(int i=0;i<n;i++){
            cin >> Arr[i];
        }
        Solution obj;
        cout<<obj.binarySearchable(Arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends