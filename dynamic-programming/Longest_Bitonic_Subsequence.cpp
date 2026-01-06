//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        
        if(n == 0)
            return 0;
            
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);
        
        int maxi = 0;
        
        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                if(nums[prev]<nums[ind]){
                    dp1[ind] = max(dp1[ind], 1+dp1[prev]);
                }
            }
        }
        
        for(int ind=n-1; ind>=0; ind--){
            for(int prev=n-1; prev>ind; prev--){
                if(nums[prev]<nums[ind]){
                    dp2[ind] = max(dp2[ind], 1+dp2[prev]);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            
            if (dp1[i] != 1 && dp2[i] != 1) {
                maxi = max(maxi, dp1[i] + dp2[i] - 1);

            }
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends