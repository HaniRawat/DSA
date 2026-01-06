//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
        vector<vector<int>>ans;
        queue<int>q;
        
        q.push(arr[0]);
        int ind = 0;
        
        while(!q.empty()){
            int size = q.size();
            vector<int>res;
            
            for(int i=0; i<size; i++){
                int temp = q.front();
                q.pop();
                
                res.push_back(temp);
                
                if(2*ind + 1 < n)
                    q.push(arr[2*ind + 1]);
                    
                if(2*ind + 2 < n)
                    q.push(arr[2*ind + 2]);
                    
                ind++;
            }
            sort(res.begin(),res.end());
            ans.push_back(res);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

        Solution ob;
        
		vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends