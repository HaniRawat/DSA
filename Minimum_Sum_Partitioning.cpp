//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int minDifference(vector<int>& arr) {
        int totalSum = 0, n = arr.size();
        
        for(int i=0; i<n; i++)
            totalSum += arr[i];
            
        vector<vector<bool>> dp(n, vector<bool>(totalSum / 2 + 1, false));
        
        for(int i=0; i<n; i++)
            dp[i][0] = true; // sum of 0 is always possible
            
        if(arr[0] <= totalSum / 2)
            dp[0][arr[0]] = true;
            
        for(int idx = 1; idx<n; idx++){
            for(int target = 1; target <= totalSum/2; target++){
                
                bool noTake = dp[idx-1][target];
                bool take = false;
                
                if(arr[idx] <= target)
                    take = dp[idx - 1][target - arr[idx]];
                    
                dp[idx][target] = take || noTake;
            }
        }
        
        int mini = INT_MAX;
        
        for(int s1 = totalSum / 2; s1 >= 0; s1--){
            
            if(dp[n-1][s1]){ // if this subset is achievable
                int s2 = totalSum - s1;
                mini = min(mini, abs(s2-s1));
                break; // closest possible subset found so stop here
            }
        }
        
        return mini;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends