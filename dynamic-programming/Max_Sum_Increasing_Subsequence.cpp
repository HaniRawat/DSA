//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int>dp(n+1, 0);
	    
	    for(int i=1; i<=n; i++){
	        dp[i] = arr[i-1];
	        
	        for(int j=1; j<i; j++){
	            if(arr[i-1] > arr[j-1]){
	                dp[i] = max(dp[i], arr[i-1]+dp[j]);
	            }
	        }
	    }
	    return *max_element(dp.begin(), dp.end());
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends