//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
        unordered_map<int,int>freq;
        int N = array.size();
        
        for(int i=0; i<N;i++){
            freq[array[i]]++;
        }
        
        priority_queue<pair<int,int>>pq;
        
        for(auto it: freq){
            pq.push({it.second,it.first});
        }
        
        vector<int>ans;
        for(int i=0; i<k; i++){
            auto ele = pq.top();
            pq.pop();
            ans.push_back(ele.second);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}
// } Driver Code Ends