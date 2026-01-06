//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> store;
    unordered_set<string>mp;
    
    void solve(int index, int n, vector<int>temp,vector<int>arr,string s){
        if(index == n){
            if(mp.find(s) == mp.end()){
                mp.insert(s);
                store.push_back(temp);
            }
            return;
        }
        
        solve(index+1, n,temp,arr,s);
        temp.push_back(arr[index]);
        s += to_string(arr[index]);
        solve(index+1,n,temp,arr,s);
    }
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(),arr.end());
        string s = "";
        vector<int>temp;
        solve(0,n,temp,arr,s);
        sort(store.begin(),store.end());
        return store;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends