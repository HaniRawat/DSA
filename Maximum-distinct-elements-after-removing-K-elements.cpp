//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxDistinctNum(int arr[], int n, int k)
    {
    	unordered_map<int,int>freq;
    	for(int i=0; i<n; i++){
    	    freq[arr[i]]++;
    	}
    	
    	priority_queue<int>pq;
    	for(auto i : freq){
    	    pq.push(i.second);
    	}
    	
    	while(pq.size() && k){
    	    int t = pq.top();
    	    pq.pop();
    	    t--;
    	    
    	    if(t > 0)
    	        pq.push(t);
    	        
    	    k--;
    	}
    	
    	return (pq.size());
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i,k;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout <<ob.maxDistinctNum(arr, n, k)<<"\n";
	  }
	return 0;
}

// } Driver Code Ends