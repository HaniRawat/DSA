//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int mx = 0; //length of longest subarray div by k
	    int remSum = 0; //remainder sum of each element
	    
	    unordered_map<int,int>mp;
	    
	    for(int i=0; i<n; i++){
	        remSum = (remSum + arr[i])%k;
	        
	        if(remSum == 0){
	            mx = max(mx,i+1);
	            continue;
	        }
	        
	        int rem = (remSum < 0) ? remSum + k : remSum;
	        
	        if(mp[rem] > 0)
	            mx = max(mx, i+1-mp[rem]);
	        else
	            mp[rem] = i+1;
	    }
	    return mx;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends