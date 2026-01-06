//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Function to calculate the sum
long long sum(int a[], int n);


// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
       int n;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       	cout << sum(arr, n)<<endl; 
    }

	return 0;
}

// } Driver Code Ends


long long sum(int a[], int n)
{
    unordered_map<int,int>mp;
    
    long long ans = 0;
    long long sum = 0;
    
    for(int i=0; i<n; i++){
        long long s = sum - mp[a[i]] * a[i] - mp[a[i] - 1] * (a[i] - 1) - mp[a[i] + 1] * (a[i] + 1);
        int foo = i - mp[a[i]] - mp[a[i] - 1] - mp[a[i] + 1];
        
        ans += foo * a[i] - s;
        
        mp[a[i]]++;
        sum += a[i];
    }
    return ans;
    
}
