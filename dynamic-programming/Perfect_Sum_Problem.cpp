//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        vector<int>prev(sum+1, 0), curr(sum+1, 0);
        prev[0] = 1;
        
        if(arr[0] <= sum)
            prev[arr[0]] += 1;
            
        int MOD = 1e9+7;
        
        for(int index = 1; index < n; index++){
            for(int target = 0; target <= sum; target++){
                int notPick = prev[target] % MOD;
                int pick = 0;
                
                if(arr[index] <= target)
                    pick = prev[target - arr[index]]% MOD;
                    
                curr[target] = (pick + notPick)% MOD;
            }
            prev = curr;
        }
        return prev[sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends