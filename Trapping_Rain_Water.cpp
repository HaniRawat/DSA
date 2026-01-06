//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    long long trappingWater(vector<int> &arr) {
        
        int size = arr.size();
        
        vector<int>prefSumMax(size);
        vector<int>sufSumMax(size);
        
        long long totalSum = 0;
        
        prefSumMax[0] = arr[0];
        
        for(int i=1; i<size; i++){
            prefSumMax[i] = max(prefSumMax[i-1], arr[i]);
        }
        
        sufSumMax[size-1] = arr[size-1];
        
        for(int i=size-2; i>=0; i--){
            sufSumMax[i] = max(sufSumMax[i+1], arr[i]);
        }
        
        for(int i=0; i<size; i++){
            if(arr[i]<prefSumMax[i] && arr[i]<sufSumMax[i]){
                totalSum += min(prefSumMax[i], sufSumMax[i])-arr[i];
            }
        }
        
        return totalSum;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;

        vector<int> a(n);

        // adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a) << endl;
    }

    return 0;
}
// } Driver Code Ends