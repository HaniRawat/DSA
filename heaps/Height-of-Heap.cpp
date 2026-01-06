//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int heapHeight(int N, int arr[]){
        int height = 0;
        
        if(N == 1)
            return 1;
        
        int index = N;
        while(index > 1){
            height++;
            int parent = index/2;
            index = parent;
        }
        
        return height;
    }
};

//{ Driver Code Starts.

int main() { 
    int t;
    cin>>t;
    while(t--){
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.heapHeight(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends