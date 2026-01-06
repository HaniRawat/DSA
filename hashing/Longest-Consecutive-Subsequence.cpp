//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        map<int,int>mp;
      
        for(int i=0; i<N; i++)
            mp[arr[i]]++;
        
        int count = 0, maxi = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it != mp.begin() && it->first == prev(it)->first+1)
                count++;
            else
                count = 1;
                
            maxi = max(count,maxi);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends